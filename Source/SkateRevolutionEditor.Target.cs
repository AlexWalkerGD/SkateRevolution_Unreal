// Copyright AlexWalkerGD

using UnrealBuildTool;
using System.Collections.Generic;

public class SkateRevolutionEditorTarget : TargetRules
{
	public SkateRevolutionEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "SkateRevolution" } );
	}
}
