#include <GLFW/glfw3.h>

typedef float float4[4];

class Display {
public:
    Display(int width, int height) : width(width), height(height) {}

    int init(void) {
        if (!glfwInit())
            return -1;

        pixels = new float4[width * height];

        window = glfwCreateWindow(width, height, "nes", NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return -1;
        }

        glfwMakeContextCurrent(window);
        return 0;
    }

    void setPixel(int index, float4 color) {
        setPixel(index, color[0], color[1], color[2], color[3]);
    }

    void setPixel(int index, float r, float g, float b, float a) {
        pixels[index][0] = r;
        pixels[index][1] = g;
        pixels[index][2] = b;
        pixels[index][3] = a;
    }

    void updateDisplay() {
        while (!glfwWindowShouldClose(window))
        {
            glClear(GL_COLOR_BUFFER_BIT);

            glDrawPixels(width, height, GL_RGBA, GL_FLOAT, pixels);

            glfwSwapBuffers(window);

            glfwPollEvents();
        }
    }

    void killDisplay() {
        glfwTerminate();
    }
private:
    float4* pixels;
    GLFWwindow* window;
    int width;
    int height;
};
