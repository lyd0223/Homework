// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Message/MessageComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMessageComponent() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UMessageComponent_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UMessageComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	void UMessageComponent::StaticRegisterNativesUMessageComponent()
	{
	}
	UClass* Z_Construct_UClass_UMessageComponent_NoRegister()
	{
		return UMessageComponent::StaticClass();
	}
	struct Z_Construct_UClass_UMessageComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMessageComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMessageComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "Message/MessageComponent.h" },
		{ "ModuleRelativePath", "Message/MessageComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMessageComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMessageComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMessageComponent_Statics::ClassParams = {
		&UMessageComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMessageComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMessageComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMessageComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMessageComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMessageComponent, 3074885013);
	template<> UNREALCLIENT_API UClass* StaticClass<UMessageComponent>()
	{
		return UMessageComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMessageComponent(Z_Construct_UClass_UMessageComponent, &UMessageComponent::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UMessageComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMessageComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
