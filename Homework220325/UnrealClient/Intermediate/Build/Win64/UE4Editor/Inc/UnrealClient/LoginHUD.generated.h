// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCLIENT_LoginHUD_generated_h
#error "LoginHUD.generated.h already included, missing '#pragma once' in LoginHUD.h"
#endif
#define UNREALCLIENT_LoginHUD_generated_h

#define UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_SPARSE_DATA
#define UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_RPC_WRAPPERS
#define UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_RPC_WRAPPERS_NO_PURE_DECLS
#define UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALoginHUD(); \
	friend struct Z_Construct_UClass_ALoginHUD_Statics; \
public: \
	DECLARE_CLASS(ALoginHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(ALoginHUD)


#define UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_INCLASS \
private: \
	static void StaticRegisterNativesALoginHUD(); \
	friend struct Z_Construct_UClass_ALoginHUD_Statics; \
public: \
	DECLARE_CLASS(ALoginHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(ALoginHUD)


#define UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALoginHUD(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALoginHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALoginHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALoginHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALoginHUD(ALoginHUD&&); \
	NO_API ALoginHUD(const ALoginHUD&); \
public:


#define UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALoginHUD(ALoginHUD&&); \
	NO_API ALoginHUD(const ALoginHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALoginHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALoginHUD); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALoginHUD)


#define UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_LoginUI() { return STRUCT_OFFSET(ALoginHUD, m_LoginUI); }


#define UnrealClient_Source_UnrealClient_Login_LoginHUD_h_7_PROLOG
#define UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_RPC_WRAPPERS \
	UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_INCLASS \
	UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_INCLASS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Login_LoginHUD_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCLIENT_API UClass* StaticClass<class ALoginHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UnrealClient_Source_UnrealClient_Login_LoginHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
