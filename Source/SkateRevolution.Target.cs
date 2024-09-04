// Copyright AlexWalkerGD

using UnrealBuildTool;
using System.Collections.Generic;

public class SkateRevolutionTarget : TargetRules
{
	public SkateRevolutionTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "SkateRevolution" } );
	}
}
