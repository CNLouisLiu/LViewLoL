#pragma once
#include "stb_image.h"
#include <d3d11.h>
#include <functional>

class Texture2D {

public:
	static Texture2D* LoadFromFile(ID3D11Device* dxDevice, std::string file);
public:
	ID3D11ShaderResourceView* resourceView;
	int width, height;
};