#include "raylib.h"

#include <cstring>
#include <string>

static int g_windowWidth = 1280;
static int g_windowHeight = 720;
static int g_configFlags = 0;
static float g_targetFrameTime = 1.0f / 60.0f;
static int g_frameCount = 0;

void SetConfigFlags(int flags) { g_configFlags = flags; (void)g_configFlags; }

void InitWindow(int width, int height, const char *title) {
    g_windowWidth = width;
    g_windowHeight = height;
    (void)title;
}

void CloseWindow() { /* no-op for stub */ }
void DisableCursor() { /* no-op for stub */ }
void EnableCursor() { /* no-op for stub */ }
void SetMouseCursor(int cursor) { (void)cursor; }
void SetTargetFPS(int fps) {
    if (fps > 0)
        g_targetFrameTime = 1.0f / (float)fps;
}

bool WindowShouldClose() {
    // Auto-exit after ~10 seconds to avoid infinite loops when running headless.
    return g_frameCount++ > 600;
}

float GetFrameTime() { return g_targetFrameTime; }

Vector2 GetMouseDelta() { return {0.0f, 0.0f}; }

int GetScreenWidth() { return g_windowWidth; }
int GetScreenHeight() { return g_windowHeight; }

void BeginDrawing() {}
void EndDrawing() {}
void ClearBackground(Color color) { (void)color; }
void BeginMode3D(Camera3D camera) { (void)camera; }
void EndMode3D() {}

void DrawPlane(Vector3 centerPos, Vector2 size, Color color) {
    (void)centerPos;
    (void)size;
    (void)color;
}

void DrawCubeV(Vector3 position, Vector3 cubeSize, Color color) {
    (void)position;
    (void)cubeSize;
    (void)color;
}

void DrawCubeWiresV(Vector3 position, Vector3 cubeSize, Color color) {
    (void)position;
    (void)cubeSize;
    (void)color;
}

void DrawSphereEx(Vector3 center, float radius, int rings, int slices, Color color) {
    (void)center;
    (void)radius;
    (void)rings;
    (void)slices;
    (void)color;
}

void DrawCylinderEx(Vector3 a, Vector3 b, float aRadius, float bRadius, int sides, Color color) {
    (void)a;
    (void)b;
    (void)aRadius;
    (void)bRadius;
    (void)sides;
    (void)color;
}

Vector2 GetWorldToScreen(Vector3 position, Camera3D camera) {
    (void)camera;
    float scale = 50.0f;
    return {(float)g_windowWidth * 0.5f + position.x * scale,
            (float)g_windowHeight * 0.5f - position.y * scale};
}

void DrawRectangle(int x, int y, int width, int height, Color color) {
    (void)x;
    (void)y;
    (void)width;
    (void)height;
    (void)color;
}

void DrawRectangleLines(int x, int y, int width, int height, Color color) {
    (void)x;
    (void)y;
    (void)width;
    (void)height;
    (void)color;
}

void DrawText(const char *text, int posX, int posY, int fontSize, Color color) {
    (void)text;
    (void)posX;
    (void)posY;
    (void)fontSize;
    (void)color;
}

void DrawCircleV(Vector2 center, float radius, Color color) {
    (void)center;
    (void)radius;
    (void)color;
}

int MeasureText(const char *text, int fontSize) {
    (void)fontSize;
    if (!text) return 0;
    int len = 0;
    while (text[len] != '\0') ++len;
    return len * 8; // rough fixed-width estimate
}

RenderTexture2D LoadRenderTexture(int width, int height) {
    RenderTexture2D t = {};
    t.texture.width = width;
    t.texture.height = height;
    return t;
}

void UnloadRenderTexture(RenderTexture2D target) { (void)target; }

void BeginTextureMode(RenderTexture2D target) { (void)target; }

void EndTextureMode() {}

void DrawTexturePro(Texture2D texture, Rectangle src, Rectangle dst, Vector2 origin, float rotation, Color tint) {
    (void)texture; (void)src; (void)dst; (void)origin; (void)rotation; (void)tint;
}

void ToggleFullscreen() {}

bool IsKeyDown(int key) {
    (void)key;
    return false;
}

bool IsKeyPressed(int key) {
    (void)key;
    return false;
}

int GetCharPressed() { return 0; }

Color Fade(Color c, float alpha) {
    if (alpha < 0.0f)
        alpha = 0.0f;
    if (alpha > 1.0f)
        alpha = 1.0f;
    Color out = c;
    out.a = (unsigned char)((float)c.a * alpha);
    return out;
}

Color ColorFromNormalized(Vector4 v) {
    auto clamp = [](float f) {
        if (f < 0.0f)
            return 0.0f;
        if (f > 1.0f)
            return 1.0f;
        return f;
    };
    Color c = {0, 0, 0, 255};
    c.r = (unsigned char)(255.0f * clamp(v.x));
    c.g = (unsigned char)(255.0f * clamp(v.y));
    c.b = (unsigned char)(255.0f * clamp(v.z));
    c.a = (unsigned char)(255.0f * clamp(v.w));
    return c;
}

const char *TextSubtext(const char *text, int position, int length) {
    static std::string buffer;
    if (!text) {
        buffer.clear();
        return buffer.c_str();
    }
    int srcLen = (int)std::strlen(text);
    if (position < 0)
        position = 0;
    if (position > srcLen)
        position = srcLen;
    if (length < 0 || position + length > srcLen)
        length = srcLen - position;
    buffer.assign(text + position, text + position + length);
    return buffer.c_str();
}
