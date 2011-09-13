///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Mathematics Copyright (c) 2005 - 2011 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2011-01-15
// Updated : 2011-09-13
// Licence : This source is under MIT licence
// File    : test/core/func_packing.cpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <glm/glm.hpp>
#include <glm/gtc/half_float.hpp>
#include <glm/gtc/type_precision.hpp>
#include <vector>

int test_packHalf2x16()
{
	int Error = 0;
	
	std::vector<glm::hvec2> A;
	A.push_back(glm::hvec2(glm::half( 1.0f), glm::half( 2.0f)));
	A.push_back(glm::hvec2(glm::half(-1.0f), glm::half(-2.0f)));
	A.push_back(glm::hvec2(glm::half(-1.1f), glm::half( 1.1f)));
	
	for(std::size_t i = 0; i < A.size(); ++i)
	{
		glm::vec2 B(A[i]);
		glm::uint C = glm::packHalf2x16(B);
		glm::vec2 D = glm::unpackHalf2x16(C);
		Error += B == D ? 0 : 1;
	}
	
	return Error;
}

int test_packDouble2x32()
{
	int Error = 0;
	
	std::vector<glm::u32vec2> A;
	A.push_back(glm::u32vec2( 1, 2));
	A.push_back(glm::u32vec2(-1,-2));
	A.push_back(glm::u32vec2(-1000, 1100));
	
	for(std::size_t i = 0; i < A.size(); ++i)
	{
		glm::u32vec2 B(A[i]);
		double C = glm::packDouble2x32(B);
		glm::u32vec2 D = glm::unpackDouble2x32(C);
		Error += B == D ? 0 : 1;
	}
	
	return Error;
}

int main()
{
	int Error = 0;

	Error += test_packHalf2x16();
	Error += test_packDouble2x32();
	
	return Error;
}

