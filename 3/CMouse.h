#pragma once

#include <jni.h>

#include "JNI.h"

class CMouse final
{
public:
	CMouse(JNI* sp_jni)
		: sp_jni(sp_jni)
	{
		Init();
	}

	~CMouse()
	{
		is_init = false;
	}

	bool Init()
	{
		if (is_init)
			return true;

		jclass class_ptr{ p_jni->GetInterface()->FindClass("org/lwjgl/input/Mouse") };

		if (class_ptr == nullptr)
		{
			printf("Failed to get Mouse class\n");
			return false;
		}

		is_init = true;
		return is_init;
	}
private:
	JNI* sp_jni;
	jclass class_ptr;

	bool is_init{ false };
};