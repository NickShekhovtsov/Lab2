#include <iostream>
#include "AppWindow.h"
#include "Examples.h"
#include "Functions.h"
#include "imgui.h"
#include "Texture.h"


class Window: public AppWindow
{
	void (*func_pointer)(Texture&) = nullptr;
public:
	Window(SDL_Point windowSize):
		AppWindow(windowSize),
		texture(GetRenderer(), windowSize)
	{
		ColorsInit();
	}
	
	void Render() override
	{
		texture.Render();
	}
	
	void RenderGui() override
	{
		
		ImGui::Begin("MyWindow");
		if (ImGui::Button("Example 1"))
		{
			Example1(texture);
			func_pointer = Example1;
		}
		if (ImGui::Button("Example 2"))
		{
			Example2(texture);
			func_pointer = Example2;
		}
		if (ImGui::Button("Example 3"))
		{
			Example3(texture);
			func_pointer = Example3;
		}
		if (ImGui::Button("Example 4"))
		{
			Example4(texture);
			func_pointer = Example4;
		}
		if (ImGui::Button("Example 5"))
		{
			if (func_pointer)
			{
				Example5(texture);
				func_pointer = Example5;
			}
		}
		if (ImGui::Button("ChangeColor1"))
		{
			if (func_pointer)
			{
				ChangeColor();
				func_pointer(texture);
			}
		}

		if (ImGui::Button("ChangeColor2"))
		{
			if (func_pointer)
			{
				ChangeColor2();
				func_pointer(texture);
			}
		}
		ImGui::End();
	}
	
	void ProcessEvent(const SDL_Event& e) override
	{
		
	}
	
	Texture texture;
};


int main(int argc, char** argv)
{
	Window window({800, 600});
	
	window.Show();
	
	return 0;
}