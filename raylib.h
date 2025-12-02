
/* Minimal raylib-style stubs for this small project.
	 Purpose: Reduce overwhelming compile errors by providing the
	 minimal types and function prototypes referenced from
	 `main.cpp` in this workspace.

	 IMPORTANT:
	 - These are lightweight declarations only (not a full raylib).
	 - If you link with the real raylib, replace this file with the
		 official `raylib.h` to get full functionality.
	 - Changes made: added type definitions, enums, constant stubs,
		 and prototypes used by `main.cpp`.
	 - Deletions: none (file was previously empty). This file is
		 intentionally small and well-commented as requested.
*/

#ifndef SKYPROC_RAYLIB_STUB_H
#define SKYPROC_RAYLIB_STUB_H

#include <cmath>

#ifndef PI
#define PI 3.14159265358979323846f
#endif

#ifndef CLITERAL
#define CLITERAL(type) (type)
#endif

// Basic vector/color/camera types used by the example.
typedef struct Vector2 { float x, y; } Vector2;
typedef struct Vector3 { float x, y, z; } Vector3;
typedef struct Vector4 { float x, y, z, w; } Vector4;
typedef struct Rectangle { float x, y, width, height; } Rectangle;
typedef struct Color { unsigned char r, g, b, a; } Color;

typedef struct Camera3D { Vector3 position; Vector3 target; Vector3 up; float fovy; int projection; } Camera3D;
typedef struct Ray { Vector3 position; Vector3 direction; } Ray;
typedef struct RayCollision { bool hit; float distance; Vector3 point; Vector3 normal; } RayCollision;
typedef struct Texture2D { unsigned int id; int width; int height; int mipmaps; int format; } Texture2D;
typedef struct RenderTexture2D { unsigned int id; Texture2D texture; Texture2D depth; } RenderTexture2D;

#ifdef __cplusplus
extern "C" {
#endif

// Camera projection enum (small subset)
enum { CAMERA_PERSPECTIVE = 0, CAMERA_ORTHOGRAPHIC = 1 };

// Config flags (stubs)
enum { FLAG_WINDOW_RESIZABLE = 1<<0, FLAG_MSAA_4X_HINT = 1<<1 };

// Mouse cursor stubs
enum { MOUSE_CURSOR_ARROW = 0, MOUSE_CURSOR_IBEAM = 1, MOUSE_CURSOR_CROSSHAIR = 2 };
// Mouse buttons
enum { MOUSE_LEFT_BUTTON = 0, MOUSE_RIGHT_BUTTON = 1, MOUSE_MIDDLE_BUTTON = 2 };

// Minimal key codes used in main.cpp
enum {
		KEY_W = 0x57,
		KEY_A = 0x41,
		KEY_S = 0x53,
		KEY_D = 0x44,
		KEY_SPACE = 32,
		KEY_LEFT_SHIFT = 340,
		KEY_SLASH = 47,
		KEY_BACKSPACE = 259,
		KEY_ESCAPE = 256,
		KEY_ENTER = 257
};

// Color constants (macros to stay link-safe with real raylib)
#define BLACK    CLITERAL(Color){  0,   0,   0, 255 }
#define DARKGRAY CLITERAL(Color){ 80,  80,  80, 255 }
#define YELLOW   CLITERAL(Color){253, 249,   0, 255 }
#define GOLD     CLITERAL(Color){255, 203,   0, 255 }
#define RED      CLITERAL(Color){230,  41,  55, 255 }
#define RAYWHITE CLITERAL(Color){245, 245, 245, 255 }
#define GRAY     CLITERAL(Color){130, 130, 130, 255 }

// Basic API prototypes used by `main.cpp`.
// These are declarations only — implementations should come from the real library when linking.
void SetConfigFlags(int flags);
void InitWindow(int width, int height, const char *title);
void CloseWindow();
void DisableCursor();
void EnableCursor();
void SetMouseCursor(int cursor);
void SetTargetFPS(int fps);
bool WindowShouldClose();
float GetFrameTime();
Vector2 GetMouseDelta();
int GetScreenWidth();
int GetScreenHeight();

// Drawing / 3D helpers (declarations only)
void BeginDrawing();
void EndDrawing();
void ClearBackground(Color color);
void BeginMode3D(Camera3D camera);
void EndMode3D();
void DrawPlane(Vector3 centerPos, Vector2 size, Color color);
void DrawCubeV(Vector3 position, Vector3 size, Color color);
void DrawCubeWiresV(Vector3 position, Vector3 size, Color color);
void DrawSphereEx(Vector3 center, float radius, int rings, int slices, Color color);
void DrawCylinderEx(Vector3 a, Vector3 b, float aRadius, float bRadius, int sides, Color color);
Vector2 GetWorldToScreen(Vector3 position, Camera3D camera);
void DrawRectangle(int x, int y, int width, int height, Color color);
void DrawRectangleLines(int x, int y, int width, int height, Color color);
void DrawText(const char *text, int posX, int posY, int fontSize, Color color);
void DrawCircleV(Vector2 center, float radius, Color color);
int MeasureText(const char *text, int fontSize);
RenderTexture2D LoadRenderTexture(int width, int height);
void UnloadRenderTexture(RenderTexture2D target);
void BeginTextureMode(RenderTexture2D target);
void EndTextureMode();
void DrawTexturePro(Texture2D texture, Rectangle src, Rectangle dst, Vector2 origin, float rotation, Color tint);
void ToggleFullscreen();

// Input / keyboard
bool IsKeyDown(int key);
bool IsKeyPressed(int key);
int GetCharPressed();
bool IsMouseButtonPressed(int button);

// Color helpers
Color Fade(Color c, float alpha);
Color ColorFromNormalized(Vector4 v);

// String helper used in example.
const char *TextSubtext(const char *text, int position, int length);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // SKYPROC_RAYLIB_STUB_H
