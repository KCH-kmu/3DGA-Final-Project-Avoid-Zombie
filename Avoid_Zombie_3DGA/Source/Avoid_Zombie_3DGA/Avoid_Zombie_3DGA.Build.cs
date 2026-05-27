// Copyright 2024, Avoid_Zombie_3DGA. All Rights Reserved.

using UnrealBuildTool;

public class Avoid_Zombie_3DGA : ModuleRules
{
	public Avoid_Zombie_3DGA(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",        // Enhanced Input 시스템
			"AIModule",             // AI 컨트롤러, 감지
			"NavigationSystem",     // NavMesh 이동
			"GameplayTasks"         // AI Task
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}
