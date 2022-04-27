#include "raylib.h"
#include "raylib_32x32.c"   // Icono de la Ventana

#define WIN_ANCHO   800
#define WIN_ALTO    600
#define WIN_TITULO  "Raylib"
#define WIN_FPS     60

int main( void ) {

    // Muestra mensajes: (LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR...)
    // void TraceLog(int logLevel, const char *text, ...);
    TraceLog( LOG_INFO, "Iniciamos la ventana." );

    // -------------------
    // INICIAR LA VENTANA:
    // -------------------
    struct {
        Vector2 posicion;
        int ancho;
        int alto;
        char titulo[100];
    } win = {
        (Vector2){ 0.0f, 0.0f },
        WIN_ANCHO,
        WIN_ALTO,
        WIN_TITULO
    };
    // OTRA FORMA DE INCIAR UNA ESTRUCTURA:
    // win.ancho = WIN_ANCHO;
    // win.alto  = WIN_ALTO;
    // TextCopy( win.titulo, WIN_TITULO );

    // void InitWindow(int width, int height, const char *title);
    InitWindow( win.ancho, win.alto, win.titulo );

    // void SetWindowState(unsigned int flags)
    //   FLAG_VSYNC_HINT         // Activar el Sincronismo Vertical de la GPU (V-Sync on GPU)
    //   FLAG_FULLSCREEN_MODE    // Pone la Ventana en Pantalla Completa
    //   FLAG_WINDOW_RESIZABLE   // Hace que la Ventana sea Redimensionable.
    //   FLAG_WINDOW_HIDDEN      // Set to hide window
    //   FLAG_WINDOW_MINIMIZED   // Set to minimize window (iconify)
    //   FLAG_WINDOW_MAXIMIZED   // Set to maximize window (expanded to monitor)
    SetWindowState( FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE );

    // void SetTargetFPS(int fps);
    SetTargetFPS( WIN_FPS );         // Pone el juego a correr a 60 fotogramas por segundo.

    // ---------------------------------
    // INICIAMOS EL ICONO DE LA VENTANA:
    // ---------------------------------
    TraceLog( LOG_INFO, "Iniciamos el Icono de la ventana." );
    Image icono_main   = { 0 };
    icono_main.data    = (void*)gimp_image.pixel_data;
    icono_main.width   = (int)gimp_image.width;             // 32 PIXELS DE ANCHO
    icono_main.height  = (int)gimp_image.height;            // 32 PIXELS DE ALTO
    icono_main.format  = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8; // FORMATO RGBA 32 BITS - 4 BYTES
    icono_main.mipmaps = 1;
    // void SetWindowIcon(Image image);
    SetWindowIcon( icono_main );

    // ---------------------------------
    // TEXTO BÁSICO:
    // ---------------------------------
    const char texto1[] = "¡Hola mundo!";
    int fuente = 20;
    int longitud = MeasureText( texto1, fuente );
    const char* texto2;


    while( !WindowShouldClose() ) {   // Detecta si se ha pulsado el botón de cerrar ventana o la tecla ESC.

        BeginDrawing();                         // Empieza a dibujar.
        ClearBackground( BLACK );               // Borra toda la ventana de un color.

        win.ancho    = GetScreenWidth();        // Retorna el ancho de la ventana en pixels (int)
        win.alto     = GetScreenHeight();       // Retorna el alto  de la ventana en pixels (int)
        win.posicion = GetWindowPosition();     // Retorna la posición de la ventana (Vector2) { float, float }

        // void DrawText(const char *text, int posX, int posY, int fontSize, Color color);       // Draw text (using default font)
        DrawText( texto1, ( win.ancho - longitud  ) / 2, ( win.alto  - fuente ) / 2, fuente, WHITE );

        // const char *TextFormat(const char *text, ...);
        texto2 = TextFormat( "Posición( %i x %i )", (int)win.posicion.x, (int)win.posicion.y );
        DrawText( texto2, fuente , fuente * 1, fuente, WHITE );

        texto2 = TextFormat( "Tamaño( %i x %i )", win.ancho, win.alto );
        DrawText( texto2, fuente , fuente * 2, fuente, WHITE );

        texto2 = TextFormat( "Tiempo transcurrido: %02.02f ms", GetFrameTime()*1000 );
        DrawText( texto2, fuente , fuente * 3, fuente, WHITE );

        EndDrawing();           // Termina de dibujar.
    }

    TraceLog( LOG_INFO, "Liberamos memoria y cerramos todo." );
    // UnloadImage( icono_main );  // Liberamos memoria
    CloseWindow();              // Cerramos la ventana y el contexto OpenGL

    TraceLog( LOG_INFO, "Adiós, fue un placer servirle." ); // Esto no se muestra en consola.
    return 0;
}
