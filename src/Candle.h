//
//  Candle.h
//  CGProj
//

#ifndef __CGProj__Candle__
#define __CGProj__Candle__

#include "Common.h"
#include "GameObject.h"
#include "Vector3.h"
#include "PointLight.h"
#include "GameManager.h"

class Candle : public GameObject {
private:
	PointLight* _light;
	GLboolean _light_state;
public:

	Candle();
	Candle(GLdouble posx, GLdouble posy, GLdouble posz);
	~Candle();

	void render();
	void toggleLight();
};

#endif /* defined(__CGProj__Candle__) */
