// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Avoid_Zombie_3DGATarget : TargetRules
{
	public Avoid_Zombie_3DGATarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5Latest;
		ExtraModuleNames.Add("Avoid_Zombie_3DGA");
	}
}
