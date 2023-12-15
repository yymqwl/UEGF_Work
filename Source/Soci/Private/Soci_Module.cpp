// Copyright Epic Games, Inc. All Rights Reserved.

#include "Soci_Module.h"

IMPLEMENT_MODULE(FSoci_Module, Soci)


void FSoci_Module::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FSoci_Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}