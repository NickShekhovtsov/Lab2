#pragma once
#include "SDL_rect.h"
#include <cmath>

namespace Functions
{




	// R-функциональное пересечение
	inline float RAnd(float f1, float f2)
	{
		return f1 + f2 - std::sqrt(powf(f1, 2) + powf(f2, 2));
	}

	// R-функциональное объежигегте
	inline float ROr(float f1, float f2)
	{
		return f1 + f2 + std::sqrt(powf(f1, 2) + powf(f2, 2));
	}

	inline float Circle(SDL_FPoint position, float radius, SDL_FPoint args)
	{
		return powf(radius, 2) - powf(args.x - position.x, 2) - powf(args.y - position.y, 2);
	}
	inline float Circle(SDL_Point position, float radius, SDL_Point args)
	{
		return powf(radius, 2) - powf(args.x - position.x, 2) - powf(args.y - position.y, 2);
	}

}

// тип М-Образа
enum MImageType
{
	Cx, Cy, Cz, Cd
};
// тип для обозначения того, какой зоне принадлежит точка
enum FunctionZone
{
	Negative, Positive
};
// геометрическая информация о точке в пространстве
struct MImagePixelData
{
	double nx, ny, nz, nd;
	FunctionZone zone;
};

// 