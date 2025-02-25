/*************************************************************************/
/*  openxr_defs.cpp                                                      */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "openxr_defs.h"

// Our top level paths to which devices can be bound
OpenXRDefs::TopLevelPath OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_TOP_LEVEL_PATH_MAX] = {
	{ "Left hand controller", "/user/hand/left" },
	{ "Right hand controller", "/user/hand/right" },
};

// Fallback Khronos simple controller
OpenXRDefs::IOPath OpenXRDefs::simple_io_paths[] = {
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },

	{ "Menu click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/menu/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Menu click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/menu/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Select click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/select/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Select click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/select/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
};

// Original HTC Vive wands
OpenXRDefs::IOPath OpenXRDefs::vive_io_paths[] = {
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },

	{ "Menu click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/menu/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Menu click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/menu/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "System click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/system/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "System click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/system/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Squeeze click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/squeeze/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Squeeze click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/squeeze/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Trackpad", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trackpad", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Trackpad click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trackpad/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trackpad touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trackpad/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trackpad", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trackpad", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Trackpad click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trackpad/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trackpad touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trackpad/touch", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
};

// Microsoft motion controller (original WMR controllers)
OpenXRDefs::IOPath OpenXRDefs::motion_io_paths[] = {
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },

	{ "Menu click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/menu/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Menu click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/menu/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Squeeze click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/squeeze/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Squeeze click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/squeeze/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Thumbstick", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Thumbstick click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Thumbstick", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Thumbstick click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Trackpad", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trackpad", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Trackpad click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trackpad/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trackpad touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trackpad/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trackpad", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trackpad", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Trackpad click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trackpad/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trackpad touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trackpad/touch", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
};

// HP MR controller (newer G2 controllers)
OpenXRDefs::IOPath OpenXRDefs::hpmr_io_paths[] = {
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },

	{ "Menu click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/menu/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Menu click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/menu/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "X click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/x/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Y click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/y/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "A click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/a/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "B click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/b/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Squeeze", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/squeeze/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Squeeze", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/squeeze/value", OpenXRAction::OPENXR_ACTION_FLOAT },

	{ "Thumbstick", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Thumbstick click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Thumbstick", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Thumbstick click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
};

// Meta touch controller (original touch controllers, Quest 1 and Quest 2 controllers)
OpenXRDefs::IOPath OpenXRDefs::touch_io_paths[] = {
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },

	{ "Menu click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/menu/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "System click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/system/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "X click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/x/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "X touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/x/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Y click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/y/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Y touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/y/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "A click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/a/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "A touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/a/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "B click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/b/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "B touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/b/touch", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/touch", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Squeeze", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/squeeze/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Squeeze", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/squeeze/value", OpenXRAction::OPENXR_ACTION_FLOAT },

	{ "Thumbstick", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Thumbstick click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Thumbstick touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Thumbstick", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Thumbstick click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Thumbstick touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick/touch", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
};

// Valve index controller
OpenXRDefs::IOPath OpenXRDefs::index_io_paths[] = {
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },

	{ "System click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/system/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "System click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/system/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "A click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/a/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "A touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/a/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "A click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/a/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "A touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/a/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "B click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/b/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "B touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/b/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "B click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/b/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "B touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/b/touch", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trigger touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trigger touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/touch", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Squeeze", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/squeeze/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Squeeze", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/squeeze/value", OpenXRAction::OPENXR_ACTION_FLOAT },

	{ "Thumbstick", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Thumbstick click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Thumbstick touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Thumbstick", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Thumbstick click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Thumbstick touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick/touch", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Trackpad", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trackpad", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Trackpad force", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trackpad/force", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trackpad touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trackpad/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trackpad", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trackpad", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Trackpad force", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trackpad/force", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trackpad touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trackpad/touch", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
};

// Samsung odyssey controller
OpenXRDefs::IOPath OpenXRDefs::odyssey_io_paths[] = {
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },

	{ "Menu click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/menu/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Menu click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/menu/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Squeeze click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/squeeze/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Squeeze click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/squeeze/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Thumbstick", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Thumbstick click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Thumbstick", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Thumbstick click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Trackpad", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trackpad", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Trackpad click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trackpad/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trackpad touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trackpad/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trackpad", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trackpad", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Trackpad click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trackpad/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trackpad touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trackpad/touch", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
};

// Vive Cosmos controller
OpenXRDefs::IOPath OpenXRDefs::vive_cosmos_paths[] = {
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },

	{ "Menu click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/menu/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "System click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/system/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "X click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/x/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Y click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/y/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "A click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/a/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "B click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/b/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Shoulder click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/right/input/shoulder/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Shoulder click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/shoulder/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Squeeze click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/squeeze/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Squeeze click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/squeeze/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Thumbstick", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Thumbstick click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Thumbstick touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Thumbstick", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Thumbstick click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Thumbstick touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick/touch", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
};

// Vive Focus 3 controller
OpenXRDefs::IOPath OpenXRDefs::vive_focus3_paths[] = {
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },

	{ "Menu click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/menu/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "System click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/system/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "X click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/x/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Y click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/y/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "A click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/a/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "B click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/b/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trigger touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trigger touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/touch	", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Squeeze click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/squeeze/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Squeeze touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/squeeze/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Squeeze click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/squeeze/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Squeeze touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/squeeze/touch", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Thumbstick", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Thumbstick click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Thumbstick touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/thumbstick/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Thumbstick", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Thumbstick click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Thumbstick touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbstick/touch", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Thumbrest touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/thumbrest/touch", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
};

// Huawei controller
OpenXRDefs::IOPath OpenXRDefs::huawei_controller_paths[] = {
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Grip pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/grip/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },
	{ "Aim pose", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/aim/pose", OpenXRAction::OPENXR_ACTION_POSE },

	{ "Home click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/home/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Home click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/home/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Back click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/back/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Back click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/back/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Volume up click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/volume_up/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Volume up click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/volume_up/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Volume down click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/volume_down/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Volume down click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/volume_down/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trigger", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/value", OpenXRAction::OPENXR_ACTION_FLOAT },
	{ "Trigger click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trigger/click", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Trackpad", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trackpad", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Trackpad click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trackpad/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trackpad touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/input/trackpad/touch", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trackpad", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trackpad", OpenXRAction::OPENXR_ACTION_VECTOR2 },
	{ "Trackpad click", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trackpad/click", OpenXRAction::OPENXR_ACTION_BOOL },
	{ "Trackpad touch", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/input/trackpad/touch", OpenXRAction::OPENXR_ACTION_BOOL },

	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_LEFT_HAND], "/user/hand/left/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
	{ "Haptic output", &OpenXRDefs::available_top_level_paths[OpenXRDefs::OPENXR_RIGHT_HAND], "/user/hand/right/output/haptic", OpenXRAction::OPENXR_ACTION_HAPTIC },
};

OpenXRDefs::InteractionProfile OpenXRDefs::available_interaction_profiles[] = {
	{
			"Simple controller", // display_name
			"/interaction_profiles/khr/simple_controller", // openxr_path
			simple_io_paths, // io_paths
			sizeof(simple_io_paths) / sizeof(OpenXRDefs::IOPath) // io_path_count
	},
	{
			"HTC Vive wand", // display_name
			"/interaction_profiles/htc/vive_controller", // openxr_path
			vive_io_paths, // io_paths
			sizeof(vive_io_paths) / sizeof(OpenXRDefs::IOPath) // io_path_count
	},
	{
			"MS Motion controller", // display_name
			"/interaction_profiles/microsoft/motion_controller", // openxr_path
			motion_io_paths, // io_paths
			sizeof(motion_io_paths) / sizeof(OpenXRDefs::IOPath) // io_path_count
	},
	{
			"HPMR controller", // display_name
			"/interaction_profiles/hp/mixed_reality_controller", // openxr_path
			hpmr_io_paths, // io_paths
			sizeof(hpmr_io_paths) / sizeof(OpenXRDefs::IOPath) // io_path_count
	},
	{
			"Touch controller", // display_name
			"/interaction_profiles/oculus/touch_controller", // openxr_path
			touch_io_paths, // io_paths
			sizeof(touch_io_paths) / sizeof(OpenXRDefs::IOPath) // io_path_count
	},
	{
			"Index controller", // display_name
			"/interaction_profiles/valve/index_controller", // openxr_path
			index_io_paths, // io_paths
			sizeof(index_io_paths) / sizeof(OpenXRDefs::IOPath) // io_path_count
	},
	{
			"Samsung Odyssey controller", // display_name
			"/interaction_profiles/samsung/odyssey_controller", // openxr_path
			odyssey_io_paths, // io_paths
			sizeof(odyssey_io_paths) / sizeof(OpenXRDefs::IOPath) // io_path_count
	},
	{
			"Vive Cosmos controller", // display_name
			"/interaction_profiles/htc/vive_cosmos_controller", // openxr_path
			vive_cosmos_paths, // io_paths
			sizeof(vive_cosmos_paths) / sizeof(OpenXRDefs::IOPath) // io_path_count
	},
	{
			"Vive Focus 3 controller", // display_name
			"/interaction_profiles/htc/vive_focus3_controller", // openxr_path
			vive_focus3_paths, // io_paths
			sizeof(vive_focus3_paths) / sizeof(OpenXRDefs::IOPath) // io_path_count
	},
	{
			"Huawei controller", // display_name
			"/interaction_profiles/huawei/controller", // openxr_path
			huawei_controller_paths, // io_paths
			sizeof(huawei_controller_paths) / sizeof(OpenXRDefs::IOPath) // io_path_count
	},
};

int OpenXRDefs::available_interaction_profile_count = sizeof(OpenXRDefs::available_interaction_profiles) / sizeof(OpenXRDefs::InteractionProfile);

const OpenXRDefs::TopLevelPath *OpenXRDefs::get_top_level_path(const String p_top_level_path) {
	for (int i = 0; i < OPENXR_TOP_LEVEL_PATH_MAX; i++) {
		if (available_top_level_paths[i].openxr_path == p_top_level_path) {
			return &OpenXRDefs::available_top_level_paths[i];
		}
	}

	return nullptr;
}

const OpenXRDefs::InteractionProfile *OpenXRDefs::get_profile(const String p_interaction_profile_path) {
	for (int i = 0; i < available_interaction_profile_count; i++) {
		if (available_interaction_profiles[i].openxr_path == p_interaction_profile_path) {
			return &available_interaction_profiles[i];
		}
	}

	return nullptr;
}

const OpenXRDefs::IOPath *OpenXRDefs::InteractionProfile::get_io_path(const String p_io_path) const {
	for (int i = 0; i < available_interaction_profiles[i].io_path_count; i++) {
		if (io_paths[i].openxr_path == p_io_path) {
			return &io_paths[i];
		}
	}

	return nullptr;
}

const OpenXRDefs::IOPath *OpenXRDefs::get_io_path(const String p_interaction_profile_path, const String p_io_path) {
	const OpenXRDefs::InteractionProfile *profile = OpenXRDefs::get_profile(p_interaction_profile_path);
	if (profile != nullptr) {
		return profile->get_io_path(p_io_path);
	}

	return nullptr;
}

PackedStringArray OpenXRDefs::get_interaction_profile_paths() {
	PackedStringArray arr;

	for (int i = 0; i < available_interaction_profile_count; i++) {
		arr.push_back(available_interaction_profiles[i].openxr_path);
	}

	return arr;
}
