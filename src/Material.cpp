//
//  Material.cpp
//  CGProj
//

#include "Material.h"

Material::Material()
{
}

Material::~Material()
{
}

void Material::defineMaterial(GLfloat amb[], GLfloat diff[], GLfloat spec[], GLfloat shine)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
}