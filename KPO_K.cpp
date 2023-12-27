//KPO-K Novikov 3-325 Корамболь-2.1 v0.0.1

#include "framework.h"
#include "KPO_K.h"
#include "Figures.h"
#include "Processing.h"

#define MAX_LOADSTRING 100


// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


//Точка входа
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь - инициализация и подгрузка

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_KPOK, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_KPOK));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

//Регистрирует класс окна
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX); //СвМо - Задача размера структуры

    wcex.style = CS_HREDRAW | CS_VREDRAW; //Перерисовка при изм размеров
    wcex.lpfnWndProc = WndProc; //Функция обработчика сообщений
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance; //Какой-то главный хендел приложения
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_KPOK)); //Подгрузка иконки
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); //Подгружает курсор, что бы это не значило
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); //Фон окна
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_KPOK); //СвМо - указание файла меню .rc
    wcex.lpszClassName = szWindowClass; //СвМо - указатель на имя класса окна
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)); //Подгрузка маленькой иконки в названии

    return RegisterClassExW(&wcex);
}

//Сохраняет маркер экземпляра и создает главное окно
//В этой функции маркер экземпляра сохраняется в глобальной переменной, а также создается и выводится главное окно программы.
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

    HWND hWnd = CreateWindowW(szWindowClass, L"Корамболь" /*szTitle*/, WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
        0, 0, 1000, 500, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//Обрабатывает сообщения в главном окне
//
//WM_COMMAND  - обработать меню приложения
//WM_PAINT    - Отрисовка главного окна
//WM_DESTROY  - отправить сообщение о выходе и вернуться
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    SetTimer(hWnd, 1, 1000 / 60, (TIMERPROC)TimerProc); //Таймер 1/60 секунды

    switch (message)
    {
    case WM_COMMAND: //Кнопки меню
    {
        int wmId = LOWORD(wParam);
        // Разобрать выбор в меню:
        switch (wmId)
        {
        case IDM_ABOUT:
            //DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            MessageBox(NULL, L"Версия 0.0.2\n3-325 Новиков К.А.\nМАИ 2023", L"О программе", MB_OK | MB_ICONINFORMATION);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT: //Перерисовка окна
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        missile.show(hdc);
        wall.show(hdc);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY: //Удаление окна
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

//// Обработчик сообщений для окна "О программе".
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    UNREFERENCED_PARAMETER(lParam);
//    switch (message)
//    {
//    case WM_INITDIALOG:
//        return (INT_PTR)TRUE;
//
//    case WM_COMMAND:
//        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//        {
//            EndDialog(hDlg, LOWORD(wParam));
//            return (INT_PTR)TRUE;
//        }
//        break;
//    }
//
//    return (INT_PTR)FALSE;
//}
