// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Avoid_Zombie_CPP : ModuleRules
{
	public Avoid_Zombie_CPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"NavigationSystem",   // 좀비 NavMesh 이동용
			"GameplayTasks",      // AI Task용
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"RenderCore",         // HUD 캔버스 삼각형 드로잉(GWhiteTexture)용
			"GameplayTags"        // Lyra 이식 카메라 모드의 CameraTypeTag용
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Avoid_Zombie_CPP",
			"Avoid_Zombie_CPP/Variant_Platforming",
			"Avoid_Zombie_CPP/Variant_Platforming/Animation",
			"Avoid_Zombie_CPP/Variant_Combat",
			"Avoid_Zombie_CPP/Variant_Combat/AI",
			"Avoid_Zombie_CPP/Variant_Combat/Animation",
			"Avoid_Zombie_CPP/Variant_Combat/Gameplay",
			"Avoid_Zombie_CPP/Variant_Combat/Interfaces",
			"Avoid_Zombie_CPP/Variant_Combat/UI",
			"Avoid_Zombie_CPP/Variant_SideScrolling",
			"Avoid_Zombie_CPP/Variant_SideScrolling/AI",
			"Avoid_Zombie_CPP/Variant_SideScrolling/Gameplay",
			"Avoid_Zombie_CPP/Variant_SideScrolling/Interfaces",
			"Avoid_Zombie_CPP/Variant_SideScrolling/UI",
			// ─── Avoid Zombie 게임 ────────────────────────────────────
			"Avoid_Zombie_CPP/Avoid_Zombie",
			"Avoid_Zombie_CPP/Avoid_Zombie/Camera"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
