// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Login/LoginHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLoginHUD() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_ALoginHUD_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_ALoginHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
	UNREALCLIENT_API UClass* Z_Construct_UClass_ULoginUI_NoRegister();
// End Cross Module References
	void ALoginHUD::StaticRegisterNativesALoginHUD()
	{
	}
	UClass* Z_Construct_UClass_ALoginHUD_NoRegister()
	{
		return ALoginHUD::StaticClass();
	}
	struct Z_Construct_UClass_ALoginHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_LoginUI_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_m_LoginUI;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALoginHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALoginHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "Login/LoginHUD.h" },
		{ "ModuleRelativePath", "Login/LoginHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALoginHUD_Statics::NewProp_m_LoginUI_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Login/LoginHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALoginHUD_Statics::NewProp_m_LoginUI = { "m_LoginUI", nullptr, (EPropertyFlags)0x002008000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALoginHUD, m_LoginUI), Z_Construct_UClass_ULoginUI_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALoginHUD_Statics::NewProp_m_LoginUI_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALoginHUD_Statics::NewProp_m_LoginUI_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALoginHUD_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALoginHUD_Statics::NewProp_m_LoginUI,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALoginHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALoginHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ALoginHUD_Statics::ClassParams = {
		&ALoginHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ALoginHUD_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ALoginHUD_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ALoginHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ALoginHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALoginHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ALoginHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALoginHUD, 3288877868);
	template<> UNREALCLIENT_API UClass* StaticClass<ALoginHUD>()
	{
		return ALoginHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALoginHUD(Z_Construct_UClass_ALoginHUD, &ALoginHUD::StaticClass, TEXT("/Script/UnrealClient"), TEXT("ALoginHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALoginHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
