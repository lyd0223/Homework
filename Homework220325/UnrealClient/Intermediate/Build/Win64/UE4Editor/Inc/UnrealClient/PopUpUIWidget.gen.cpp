// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Login/PopUpUIWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePopUpUIWidget() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_UPopUpUIWidget_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_UPopUpUIWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	DEFINE_FUNCTION(UPopUpUIWidget::execPopUpUIOff)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PopUpUIOff();
		P_NATIVE_END;
	}
	void UPopUpUIWidget::StaticRegisterNativesUPopUpUIWidget()
	{
		UClass* Class = UPopUpUIWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "PopUpUIOff", &UPopUpUIWidget::execPopUpUIOff },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPopUpUIWidget_PopUpUIOff_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPopUpUIWidget_PopUpUIOff_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Login/PopUpUIWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPopUpUIWidget_PopUpUIOff_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPopUpUIWidget, nullptr, "PopUpUIOff", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPopUpUIWidget_PopUpUIOff_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPopUpUIWidget_PopUpUIOff_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPopUpUIWidget_PopUpUIOff()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPopUpUIWidget_PopUpUIOff_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UPopUpUIWidget_NoRegister()
	{
		return UPopUpUIWidget::StaticClass();
	}
	struct Z_Construct_UClass_UPopUpUIWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_PopUpMessageString_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_m_PopUpMessageString;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPopUpUIWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPopUpUIWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPopUpUIWidget_PopUpUIOff, "PopUpUIOff" }, // 1691525027
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPopUpUIWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Login/PopUpUIWidget.h" },
		{ "ModuleRelativePath", "Login/PopUpUIWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPopUpUIWidget_Statics::NewProp_m_PopUpMessageString_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "PopUpUI" },
		{ "ModuleRelativePath", "Login/PopUpUIWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UPopUpUIWidget_Statics::NewProp_m_PopUpMessageString = { "m_PopUpMessageString", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPopUpUIWidget, m_PopUpMessageString), METADATA_PARAMS(Z_Construct_UClass_UPopUpUIWidget_Statics::NewProp_m_PopUpMessageString_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPopUpUIWidget_Statics::NewProp_m_PopUpMessageString_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPopUpUIWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPopUpUIWidget_Statics::NewProp_m_PopUpMessageString,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPopUpUIWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPopUpUIWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPopUpUIWidget_Statics::ClassParams = {
		&UPopUpUIWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPopUpUIWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPopUpUIWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPopUpUIWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPopUpUIWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPopUpUIWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPopUpUIWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPopUpUIWidget, 2588770212);
	template<> UNREALCLIENT_API UClass* StaticClass<UPopUpUIWidget>()
	{
		return UPopUpUIWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPopUpUIWidget(Z_Construct_UClass_UPopUpUIWidget, &UPopUpUIWidget::StaticClass, TEXT("/Script/UnrealClient"), TEXT("UPopUpUIWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPopUpUIWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif