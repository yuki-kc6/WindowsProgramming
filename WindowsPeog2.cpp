// WindowsPeog2.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "framework.h"
#include "WindowsPeog2.h"
#include "Direct3D.h"
#include "Quad.h"
#include "Camera.h"


HWND hWnd = nullptr;

#define MAX_LOADSTRING 100

//グローバル変数の宣言
const wchar_t* WIN_CLASS_NAME = L"SAMPLE GAME WINDOW";
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

// グローバル変数:
HINSTANCE hInst;                                // 現在のインターフェイス
WCHAR szTitle[MAX_LOADSTRING];                  // タイトル バーのテキスト
WCHAR szWindowClass[MAX_LOADSTRING];            // メイン ウィンドウ クラス名

// このコード モジュールに含まれる関数の宣言を転送します:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);


//WinMainの引数の意味
//第1引数　HINSTANCE
//インスタンスハンドル。アプリを識別するための一意の値が入る。
//第2引数　HINSTANCE
//これもインスタンスハンドルだが、Win16APIとの互換性を保つために用意された引数。常にNULLが入る。
//第３引数　LPSTR
//コマンドライン引数として渡された文字列のポインタが格納される引数
//第４引数　int
//アプリをどのような形式で表示するかを示したもの
//エントリーポイント


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ここにコードを挿入してください。

    //szWindowClass = WIN_CLASS_NAME;


    // グローバル文字列を初期化する
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPEOG2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

  
   
    // アプリケーション初期化の実行:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HRESULT hr;
    hr = Direct3D::Initialize(WINDOW_WIDTH, WINDOW_HEIGHT, hWnd);
    if (FAILED(hr))
    {
        return 0;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPEOG2));

    
    
    Camera::Initialize();
    




    //メッセージループとは、メッセージキューに格納されたメッセージを取り出し、ウインドウプロシージャに渡す処理である。

    MSG msg = {};

    Quad* q = new Quad();
    hr = q->Initialize();
    if (FAILED(hr))
    {
        return 0;
    }

    ZeroMemory(&msg, sizeof(msg));
    //メッセージループ（何か起きるのを待つ）
    while (msg.message != WM_QUIT)

    {

        //メッセージあり

        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))

        {

            TranslateMessage(&msg);

            DispatchMessage(&msg);

        }



        //メッセージなし

        else
        {
            //ゲームの処理

            Camera::Update();

            Direct3D::BeginDraw();

            
            //描画処理

            XMMATRIX mat = XMMatrixRotationY(XMConvertToRadians(45));

            q->Draw(mat);

            Direct3D::EndDraw();

        }

    }

    //解放処理
    q->Release();
    SAFE_DELETE(q);


    Direct3D::Release();
    


    return (int)msg.wParam;
}



//
//  関数: MyRegisterClass()
//
//  目的: ウィンドウ クラスを登録します。
//



//構造体の意味
//cbSize      構造体のサイズを入れる。通常sizeof(WNDCLASSEX)とする。
//style       CS_で始まる定数のフラグの組み合わせ。 ほとんどの場合、CS_HREDRAW | CS_VREDRAWを入れれば良い。
//lpfnWndProc ウィンドウ関数名（ウィンドウプロシージャ名）を指定する。
//cbClsExtra  構造体が使用する「余分な(extra)」メモリのサイズを指定する。 通常は0にしておく。
//cbWndExtra  ウィンドウが使用する「余分な(extra)」メモリのサイズ。 これも0にしておく。
//hInstance   ウィンドウ関数を所有しているモジュールのインスタンスハンドルを指定。 WinMainの第一引数を使用する。
//hIcon       アイコンリソースへのハンドルを指定。 NULLにするとコンソールアプリのアイコンを使用する。
//hCursor     カーソルリソースへのハンドルを指定。 NULLにすると、マウスカーソルがウィンドウの中に移動したときに 常に明示的にカーソルをセットしなければならない。
//
//hbrBackground   ウィンドウの背景色をブラシ色（後述）で指定。 CreateBrushとかCreateSolidBrushの戻り値も使えるが、 システムカラーの定数(COLOR_WINDOWなど)も使える。 それに1を足してHBRUSHにキャストすると言う方法である。 指定したブラシは、クラスがフリー(free)になったときに システムが自動的に削除するので、アプリケーション側では削除しない。
//lpszMenuName    メニューリソースを示すNULLで終わる文字列か、 リソースの識別子をMAKEINTRESOURCEマクロを使って指定する。
//lpszClassName   作成するウィンドウクラスの名前を文字列で指定する。 通常は、アプリケーション名を指定する。
//hIconSm         アプリケーションと関連(associate)するスモールアイコンを指定する。 NULLにするとhIconを無理矢理縮めたものを使う。構造体に値を一通り入れたら、RegisterClassEx関数を呼ぶ。

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPEOG2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName =  WIN_CLASS_NAME;
    wcex.hIconSm =  LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   関数: InitInstance(HINSTANCE, int)
//
//   目的: インスタンス ハンドルを保存して、メイン ウィンドウを作成します
//
//   コメント:
//
//        この関数で、グローバル変数でインスタンス ハンドルを保存し、
//        メイン プログラム ウィンドウを作成および表示します。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{

   hInst = hInstance; // グローバル変数にインスタンス ハンドルを格納する

   /*CreateWindowEｘの引数と戻り値の意味
       dwExStyle　	WS_EX_ から始まる拡張ウィンドウスタイルを表す定数。
       lpClassName	ウィンドウクラスの名前、またはウィンドウクラスを表すアトム。
       lpWindowName	ウィンドウの名前。
       dwStyle		WS_ から始まるウィンドウのスタイルを表す定数
       x		    スクリーンの左上隅を原点とする X 座標で指定する、ウィンドウを表示する水平方向の初期位置。
       y		    スクリーンの左上隅を原点とする Y 座標で指定する、ウィンドウを表示する垂直方向の初期位置。
       nWidth		ウィンドウの幅。
       nHeight		ウィンドウの高さ。
       hWndParent	親ウィンドウのハンドル。
       hMenu		メニューのハンドル、または子ウィンドウの ID。
       hInstance	ウィンドウに関連付けられるインスタンスのハンドル。
       lpParam		生成するウィンドウに渡す任意のパラメータ。

       戻り値		作成されたウィンドウのハンドル。失敗すると NULL。*/


       //ウィンドウサイズの計算
   RECT winRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
   AdjustWindowRect(&winRect, WS_OVERLAPPEDWINDOW, FALSE);
   int winW = winRect.right - winRect.left;     //ウィンドウ幅
   int winH = winRect.bottom - winRect.top;     //ウィンドウ高さ


    hWnd = CreateWindow(WIN_CLASS_NAME, WIN_CLASS_NAME, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, winW, winH, nullptr, nullptr, hInstance, nullptr);




   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  関数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: メイン ウィンドウのメッセージを処理します。
//
//  WM_COMMAND  - アプリケーション メニューの処理
//  WM_PAINT    - メイン ウィンドウを描画する
//  WM_DESTROY  - 中止メッセージを表示して戻る


//コールバックとは
//OSに呼んでもらう関数
//ウィンドウプロシージャとは、受け取ったメッセージを処理する関数である。
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 選択されたメニューの解析:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: HDC を使用する描画コードをここに追加してください...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// バージョン情報ボックスのメッセージ ハンドラーです。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
