// -----------------------------------------------------------------------
//                            INICIO MAIN.C
// -----------------------------------------------------------------------

// --------------
// Preprocesador:
// --------------
#include "raylib.h"         // Incluimos la librería Raylib
#include "raylib_32x32.c"   // Incluimos el Icono de la Ventana

#include <stdint.h>
#include <float.h>

#define WIN_ANCHO   900         // Definimos el ancho de la ventana
#define WIN_ALTO    700         // Definimos el alto  de la ventana
#define WIN_FPS     60          // Definimos los Fotogramas Por Segundo
#define WIN_TITULO  "Raylib"    // Definimos el título de la ventana

// -------------------
// Variables Globales:
// -------------------
int   fontSize   = 20;      // Tamaño de la fuente de texto
Color fontColor  = WHITE;   // Color de la fuente de texto
Color fondoColor = BLACK;   // Color del fondo de la ventana

// -------------------------------------
// Declaramos algunas funciones propias:
// -------------------------------------
void IniciaVentana( int ancho, int alto, int fps, const char* titulo );
void EmpiezaDibujo( void );
void PosicionX( int x );    // Usada por fun Escribe() para posicionar el texto
void PosicionY( int y );    // Usada por fun Escribe() para posicionar el texto
void Escribe( const char *texto );
void EscribeCentrado( const char *texto );
void TerminaDibujo( void );
void CierraVentana( void );

// -----------------------------------------------------------------------
//                       INICIO Función principal
// -----------------------------------------------------------------------
// Muestra mensajes por la consola: (LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR...)
// void TraceLog( int logLevel, const char *text, ... );
//
// Formatea cadenas de texto:
// const char *TextFormat( const char *text, ... );
int main( void ) {

    IniciaVentana( WIN_ANCHO, WIN_ALTO, WIN_FPS, WIN_TITULO );

    while( !WindowShouldClose() ) { // Detecta si se ha pulsado el botón de cerrar ventana o la tecla ESC.

        EmpiezaDibujo();


        EscribeCentrado( "¡Hola Mundo!" );


/*
    // ENTEROS SIN SIGNO:
    // ------------------
    // unsigned char            ->  unsigned char       -> sizeof( unsigned char )      -> 5U;   -> %hhu | %hhc | %c
    // unsigned short int       ->  unsigned short      -> sizeof( unsigned short )     -> 5U;   -> %hu  | %hc  | %C
    // unsigned int             ->  unsigned            -> sizeof( unsigned )           -> 5U;   -> %u
    // unsigned long int        ->  unsigned long       -> sizeof( unsigned long )      -> 5UL;  -> %lu
    // unsigned long long int   ->  unsigned long long  -> sizeof( unsigned long long ) -> 5ULL; -> %llu
        PosicionX( 10 );
        Escribe( "ENTEROS SIN SIGNO:" );
        Escribe( TextFormat( "sizeof unsigned char  = %d", sizeof( unsigned char ) ) );
        Escribe( TextFormat( "sizeof unsigned short = %d", sizeof( unsigned short ) ) );
        Escribe( TextFormat( "sizeof unsigned       = %d", sizeof( unsigned ) ) );
        Escribe( TextFormat( "sizeof unsigned long  = %d", sizeof( unsigned long ) ) );
        Escribe( TextFormat( "sizeof unsigned long long = %d", sizeof( unsigned long long ) ) );
        unsigned char      a = 255;                     // UINT8_MAX;   // 5;
        unsigned char      b = 0;                       // 0;           // -5;
        unsigned short     c = 65535;                   // UINT16_MAX;  // 5;
        unsigned short     d = 0;                       // 0;           // -5;
        unsigned           e = 4294967295U;             // INT32_MAX;   // 5U;
        unsigned           f = 0;                       // 0;           // -5U;
        unsigned long      g = 4294967295U;             // INT32_MAX;   // 5UL;
        unsigned long      h = 0;                       // INT32_MAX;   // -5UL;
        unsigned long long i = 18446744073709551615ULL; // INT64_MAX;   // 5ULL;
        unsigned long long j = 0;                       // INT64_MAX;   // -5ULL;
        Escribe( TextFormat( "unsigned char  = de %hhu a %hhu", a, b ) );      // %hhu | %hhc | %c
        Escribe( TextFormat( "unsigned short = de %hu a %hu", c, d ) );        // %hu  | %hc  | %C
        Escribe( TextFormat( "unsigned       = de %u a %u", e, f ) );          // %u
        Escribe( TextFormat( "unsigned long  = de %lu a %lu", g, h ) );        // %lu
        Escribe( TextFormat( "unsigned long long = de %llu a %llu", i, j ) );  // %llu
*/

/*
    // ENTEROS CON SIGNO:
    // ------------------
    // signed  char             ->  char        -> sizeof( char )       -> 5;   -> %hhd | %hhi | %hhc | %c
    // signed  short int        ->  short       -> sizeof( short )      -> 5;   -> %hd  | %hi  | %hc  | %C
    // signed  int              ->  int         -> sizeof( int )        -> 5;   -> %d   | %i
    // signed  long int         ->  long        -> sizeof( long )       -> 5L;  -> %ld  | %li
    // signed  long long int    ->  long long	-> sizeof( long long )  -> 5LL; -> %lld | %lli
        PosicionX( 10 );
        Escribe( "ENTEROS CON SIGNO:" );
        Escribe( TextFormat( "sizeof char  = %d", sizeof( char ) ) );
        Escribe( TextFormat( "sizeof short = %d", sizeof( short ) ) );
        Escribe( TextFormat( "sizeof int   = %d", sizeof( int ) ) );
        Escribe( TextFormat( "sizeof long  = %d", sizeof( long ) ) );
        Escribe( TextFormat( "sizeof long long = %d", sizeof( long long ) ) );
        char      a = 127;                          //  INT8_MAX;    // 5;
        char      b = -128;                         //  INT8_MIN;    // -5;
        short     c = 32767;                        // INT16_MAX;    // 5;
        short     d = (-32768);                     // INT16_MAX;    // -5;
        int       e = 32767;                        // INT32_MAX;    // 5;
        int       f = (-32768);                     // INT32_MIN;    // -5;
        long      g = 2147483647L;                  // INT32_MAX;    // 5L;
        long      h = (-2147483646L);               // INT32_MAX;    // -5L;
        long long i = 9223372036854775807LL;        // INT64_MAX;    // 5LL;
        long long j = (-9223372036854775806LL );    // INT64_MAX;    // -5LL;
        Escribe( TextFormat( "char      = de %hhd a %hhd", a, b ) ); // %hhd | %hhi | %hhc | %c
        Escribe( TextFormat( "short     = de %hd a %hd", c, d ) );   // %hd  | %hi  | %hc  | %C
        Escribe( TextFormat( "int       = de %d a %d", e, f ) );     // %d   | %i
        Escribe( TextFormat( "long      = de %ld a %ld", g, h ) );   // %ld  | %li
        Escribe( TextFormat( "long long = de %lld a %lld", i, j ) ); // %lld | %lli
*/

/*
    // ENTEROS DE TIPO EXACTO:
    // -----------------------
    // #include <stdint.h>
    // typedef signed   char        int8_t;     // 1 Byte  |  8 bits
    // typedef unsigned char        uint8_t;	// 1 Byte  |  8 bits
    // typedef short                int16_t;	// 2 Bytes | 16 bits
    // typedef unsigned short       uint16_t;	// 2 Bytes | 16 bits
    // typedef int                  int32_t;	// 4 Bytes | 32 bits
    // typedef unsigned             uint32_t;	// 4 Bytes | 32 bits
    // typedef long long            int64_t;	// 8 Bytes | 64 bits
    // typedef unsigned long long   uint64_t;	// 8 Bytes | 64 bits
        PosicionX( 10 );
        Escribe( "ENTEROS DE TIPO EXACTO:" );
        Escribe( TextFormat( "sizeof int8_t   = %d", sizeof( int8_t) ) );
        Escribe( TextFormat( "sizeof uint8_t  = %d", sizeof( uint8_t ) ) );
        Escribe( TextFormat( "sizeof int16_t  = %d", sizeof( int16_t) ) );
        Escribe( TextFormat( "sizeof uint16_t = %d", sizeof( uint16_t ) ) );
        Escribe( TextFormat( "sizeof int32_t  = %d", sizeof( int32_t) ) );
        Escribe( TextFormat( "sizeof uint32_t = %d", sizeof( uint32_t ) ) );
        Escribe( TextFormat( "sizeof int64_t  = %d", sizeof( int64_t) ) );
        Escribe( TextFormat( "sizeof uint64_t = %d", sizeof( uint64_t ) ) );
        int8_t   a = 25;    // %hhd | %hhi | %hhc | %c
        uint8_t  b = 25U;   // %hhu | %hhc | %c
        int16_t  c = 25;    // %hd  | %hi  | %hc  | %C
        uint16_t d = 25U;   // %hu  | %hc  | %C
        int32_t  e = 25;    // %d   | %i
        uint32_t f = 25U;   // %u
        int64_t  g = 25LL;  // %lld | %lli
        uint64_t h = 25ULL; // %llu
*/


/*
    // ENTEROS EN BINARIO, HEXADECIMA Y OCTAL:
    // ---------------------------------------
        PosicionX( 10 );
        Escribe( "ENTEROS EN BINARIO, HEXADECIMA Y OCTAL:" );
        // Binario:
        char a = 0b00000000; // Binario digitos { 0, 1 }
        char b = 0B11111111;
        Escribe( TextFormat( "Binario a = %hhd", a ) );
        Escribe( TextFormat( "Binario b = %hhd", b ) );
        Escribe( TextFormat( "Binario b = %hhu", b ) );

        // Hexadecimal: 0xFF; 0x5bac; -> %x | %X
        unsigned c = 0x0a;  // Hexadecimal digitos { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
        unsigned d = 0xFF;  // Hexadecimal letras  { A, B, C, D, E, F }
        Escribe( TextFormat( "Hexadecimal c = %x = %u", c, c ) );
        Escribe( TextFormat( "Hexadecimal d = %X = %u", d, d ) );

        // Octal: 07;  -057;  03456;  -> %o
        int e = 07;	// OJO! si empieza por cero es base Octal.
        int f = 027;	// OJO! digitos { 0, 1, 2, 3, 4, 5, 6, 7 }
        int g = -027;   // No es -27 pues no es base decimal, es
        Escribe( TextFormat( "Octal e = %o = %d", e, e ) );
        Escribe( TextFormat( "Octal f = %o = %d", f, f ) );
        Escribe( TextFormat( "Octal g = %o = %d", g, g ) );
*/


/*
    // REALES FLOTANTES:
    // #include <float.h>
    // float        -> sizeof( float )          -> 5.5F;    -> %f   | %e  | %E
    // double       -> sizeof( double )         -> 5.5D;    -> %f   | %e  | %E
    // long double  -> sizeof( long double )    -> 5.5L;    -> %lf  | %le | %LE
        PosicionX( 10 );
        Escribe( "REALES FLOTANTES:" );
        Escribe( TextFormat( "sizeof float       = %d", sizeof( float ) ) );
        Escribe( TextFormat( "sizeof double      = %d", sizeof( double ) ) );
        Escribe( TextFormat( "sizeof long double = %d", sizeof( long double ) ) );

        Escribe( TextFormat( "FLT_DIG  = %i", FLT_DIG  ) );
        Escribe( TextFormat( "DBL_DIG  = %i", DBL_DIG  ) );
        Escribe( TextFormat( "LDBL_DIG = %i", LDBL_DIG ) );

        Escribe( TextFormat( "float       de %e a %e", FLT_MAX, FLT_MIN ) );
        Escribe( TextFormat( "double      de %e a %e", DBL_MAX, DBL_MIN ) );
        Escribe( TextFormat( "long double de %le a %le", LDBL_MAX, LDBL_MIN ) ); // No funciona

        float  a = 1.0F / 3.0F;
        double b = 1.0D / 3.0D;
        long double c = 1.0L / 3.0L;
        Escribe( TextFormat( "float  = %.28f", a ) );
        Escribe( TextFormat( "double = %.28f", b ) );
        Escribe( TextFormat( "long double = %.28Lf", c ) );              // No funciona
        Escribe( TextFormat( "long double cast = %.28f", (double)c ) );  // Casting a double
        Escribe( TextFormat( "double en exponente = %e", b ) );
        Escribe( TextFormat( "long double en exponente = %le", c ) );             // No funciona
        Escribe( TextFormat( "long double en exponente cast = %e", (double)c ) ); // Casting a double
*/

        TerminaDibujo();

    }

    CierraVentana();
    return 0;
}
// -----------------------------------------------------------------------
//                        FIN Función principal
// -----------------------------------------------------------------------

// -------------------------------------
// Implementamos las funciones propias:
// -------------------------------------
void IniciaVentana( int ancho, int alto, int fps, const char* titulo ) {
    // void InitWindow(int width, int height, const char *title);
    InitWindow( ancho, alto, titulo );

    // void SetWindowState(unsigned int flags)
    //   FLAG_VSYNC_HINT         // Activar el Sincronismo Vertical de la GPU (V-Sync on GPU)
    //   FLAG_FULLSCREEN_MODE    // Pone la Ventana en Pantalla Completa
    //   FLAG_WINDOW_RESIZABLE   // Hace que la Ventana sea Redimensionable.
    //   FLAG_WINDOW_HIDDEN      // Set to hide window
    //   FLAG_WINDOW_MINIMIZED   // Set to minimize window (iconify)
    //   FLAG_WINDOW_MAXIMIZED   // Set to maximize window (expanded to monitor)
    SetWindowState( FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE );

    // void SetTargetFPS(int fps);
    SetTargetFPS( fps );         // Pone el juego a correr a 60 fotogramas por segundo.

    // INICIAMOS EL ICONO DE LA VENTANA:
    Image icono_main   = { 0 };
    icono_main.data    = (void*)gimp_image.pixel_data;
    icono_main.width   = (int)gimp_image.width;             // 32 PIXELS DE ANCHO
    icono_main.height  = (int)gimp_image.height;            // 32 PIXELS DE ALTO
    icono_main.format  = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8; // FORMATO RGBA 32 BITS - 4 BYTES
    icono_main.mipmaps = 1;
    // void SetWindowIcon(Image image);
    SetWindowIcon( icono_main );
}

void EmpiezaDibujo( void ) {
    BeginDrawing();             // Empieza a dibujar.
    ClearBackground( fondoColor );   // Borra toda la ventana de un color.
}

// -------------------
// Variables Privadas:
// -------------------
static int posicionX = 0;
static int posicionY = 0;
void PosicionX( int x ) { posicionX = x; }
void PosicionY( int y ) { posicionY = y; }
void Escribe( const char *texto ) {
    DrawText( texto, posicionX, posicionY, fontSize, fontColor );
    posicionY += fontSize;
}

void EscribeCentrado( const char *texto ) {
    int ancho = MeasureText( texto, fontSize );
    int x = ( GetScreenWidth() - ancho ) >> 1;
    int y = ( GetScreenHeight() - fontSize ) >> 1;
    DrawText( texto, x, y, fontSize, fontColor );
}

void TerminaDibujo( void ) {
    posicionX = 0;
    posicionY = 0;
    EndDrawing();               // Termina de dibujar.
}

void CierraVentana( void ) {
    CloseWindow();              // Cerramos la ventana y el contexto OpenGL
}

// -----------------------------------------------------------------------
//                              FIN MAIN.C
// -----------------------------------------------------------------------
