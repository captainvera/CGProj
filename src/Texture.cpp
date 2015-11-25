//
//  Texture.cpp
//  CGProj
//

#include "Texture.h"

Texture::Texture()
{
}

Texture::~Texture()
{
}

void Texture::loadTexture(GLuint* texture, const char* path)
{
	*texture = //SOIL_load_image(path, &_width, &_height, &_channels, SOIL_LOAD_RGBA);
		SOIL_load_OGL_texture(
			path,
			SOIL_LOAD_RGB,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA
			);

	if (*texture == NULL) {
		printf("[Texture loader] \"%s\" failed to load!\n", path);
	}
}

void Texture::textureInit(GLuint texture)
{
	/*glGenTextures(1, &_textureName);
	glBindTexture(GL_TEXTURE_2D, _textureName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _text);
	SOIL_free_image_data(_text);*/

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthMask(GL_FALSE);
	glDisable(GL_DEPTH_TEST);
}

void Texture::textureEnd()
{
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDisable(GL_BLEND);
}

/*void Texture::bindTexture()
{
	glBindTexture(GL_TEXTURE_2D, _textureName);
}*/