// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealClient/Login/SignInUIWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSignInUIWidget() {}
// Cross Module References
	UNREALCLIENT_API UClass* Z_Construct_UClass_USignInUIWidget_NoRegister();
	UNREALCLIENT_API UClass* Z_Construct_UClass_USignInUIWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_UnrealClient();
// End Cross Module References
	DEFINE_FUNCTION(USignInUIWidget::execSignIn)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SignIn();
		P_NATIVE_END;
	}
	void USignInUIWidget::StaticRegisterNativesUSignInUIWidget()
	{
		UClass* Class = USignInUIWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SignIn", &USignInUIWidget::execSignIn },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USignInUIWidget_SignIn_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USignInUIWidget_SignIn_Statics::Function_MetaDataParams[] = {
		{ "Category", "SignIn|SignIn" },
		{ "ModuleRelativePath", "Login/SignInUIWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USignInUIWidget_SignIn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USignInUIWidget, nullptr, "SignIn", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USignInUIWidget_SignIn_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USignInUIWidget_SignIn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USignInUIWidget_SignIn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USignInUIWidget_SignIn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USignInUIWidget_NoRegister()
	{
		return USignInUIWidget::StaticClass();
	}
	struct Z_Construct_UClass_USignInUIWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_IDString_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_m_IDString;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_m_PWString_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_m_PWString;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USignInUIWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USignInUIWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USignInUIWidget_SignIn, "SignIn" }, // 2356922894
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignInUIWidget_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Login/SignInUIWidget.h" },
		{ "ModuleRelativePath", "Login/SignInUIWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignInUIWidget_Statics::NewProp_m_IDString_MetaData[] = {
		{ "Category", "SignInInfo" },
		{ "ModuleRelativePath", "Login/SignInUIWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USignInUIWidget_Statics::NewProp_m_IDString = { "m_IDString", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USignInUIWidget, m_IDString), METADATA_PARAMS(Z_Construct_UClass_USignInUIWidget_Statics::NewProp_m_IDString_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USignInUIWidget_Statics::NewProp_m_IDString_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USignInUIWidget_Statics::NewProp_m_PWString_MetaData[] = {
		{ "Category", "SignInInfo" },
		{ "ModuleRelativePath", "Login/SignInUIWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USignInUIWidget_Statics::NewProp_m_PWString = { "m_PWString", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USignInUIWidget, m_PWString), METADATA_PARAMS(Z_Construct_UClass_USignInUIWidget_Statics::NewProp_m_PWString_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USignInUIWidget_Statics::NewProp_m_PWString_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USignInUIWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USignInUIWidget_Statics::NewProp_m_IDString,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USignInUIWidget_Statics::NewProp_m_PWString,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USignInUIWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USignInUIWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USignInUIWidget_Statics::ClassParams = {
		&USignInUIWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USignInUIWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USignInUIWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_USignInUIWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USignInUIWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USignInUIWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USignInUIWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USignInUIWidget, 676003275);
	template<> UNREALCLIENT_API UClass* StaticClass<USignInUIWidget>()
	{
		return USignInUIWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USignInUIWidget(Z_Construct_UClass_USignInUIWidget, &USignInUIWidget::StaticClass, TEXT("/Script/UnrealClient"), TEXT("USignInUIWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USignInUIWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
