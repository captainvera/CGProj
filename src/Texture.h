//
//  Texture.h
//  CGProj
//

#ifndef __CGProj__Texture__
#define __CGProj__Texture__

#include "Common.h"
#include "SOIL.h"

#define checkImageWidth 64
#define checkImageHeight 64

class Texture {
private:
	static GLubyte _checkImage[checkImageHeight][checkImageWidth][4];
	GLuint _textureName;
	int _width, 
		_height, 
		_channels;
	//GLubyte* _text;
public:
	Texture();
	~Texture();
	void loadTexture(GLuint * texture, const char * path);
	void textureInit(GLuint texture);
	void textureEnd();
	//void generateTexture(GLuint texture);
	//void bindTexture();
};

#endif /* defined(__CGProj__Texture__) */
