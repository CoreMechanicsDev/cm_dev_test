// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class cm_dev_testEditorTarget : TargetRules
{
	public cm_dev_testEditorTarget( TargetInfo Target) : base(Target)
	{
		// Test Comment
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V7;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_8;
		ExtraModuleNames.Add("cm_dev_test");
	}
}
