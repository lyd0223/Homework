// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UNREALCLIENT_LoginUI_generated_h
#error "LoginUI.generated.h already included, missing '#pragma once' in LoginUI.h"
#endif
#define UNREALCLIENT_LoginUI_generated_h

#define UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_SPARSE_DATA
#define UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSignInUIWidgetOpen); \
	DECLARE_FUNCTION(execServerLogin); \
	DECLARE_FUNCTION(execServerConnect); \
	DECLARE_FUNCTION(execSetTeacherIP); \
	DECLARE_FUNCTION(execSetLocalIP);


#define UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSignInUIWidgetOpen); \
	DECLARE_FUNCTION(execServerLogin); \
	DECLARE_FUNCTION(execServerConnect); \
	DECLARE_FUNCTION(execSetTeacherIP); \
	DECLARE_FUNCTION(execSetLocalIP);


#define UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULoginUI(); \
	friend struct Z_Construct_UClass_ULoginUI_Statics; \
public: \
	DECLARE_CLASS(ULoginUI, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(ULoginUI)


#define UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_INCLASS \
private: \
	static void StaticRegisterNativesULoginUI(); \
	friend struct Z_Construct_UClass_ULoginUI_Statics; \
public: \
	DECLARE_CLASS(ULoginUI, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealClient"), NO_API) \
	DECLARE_SERIALIZER(ULoginUI)


#define UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULoginUI(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULoginUI) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULoginUI); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULoginUI); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULoginUI(ULoginUI&&); \
	NO_API ULoginUI(const ULoginUI&); \
public:


#define UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULoginUI(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULoginUI(ULoginUI&&); \
	NO_API ULoginUI(const ULoginUI&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULoginUI); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULoginUI); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULoginUI)


#define UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__m_IPString() { return STRUCT_OFFSET(ULoginUI, m_IPString); } \
	FORCEINLINE static uint32 __PPO__m_PortString() { return STRUCT_OFFSET(ULoginUI, m_PortString); } \
	FORCEINLINE static uint32 __PPO__m_ConnectStatusString() { return STRUCT_OFFSET(ULoginUI, m_ConnectStatusString); } \
	FORCEINLINE static uint32 __PPO__m_IDString() { return STRUCT_OFFSET(ULoginUI, m_IDString); } \
	FORCEINLINE static uint32 __PPO__m_PWString() { return STRUCT_OFFSET(ULoginUI, m_PWString); } \
	FORCEINLINE static uint32 __PPO__m_ConnectedIconColor() { return STRUCT_OFFSET(ULoginUI, m_ConnectedIconColor); }


#define UnrealClient_Source_UnrealClient_Login_LoginUI_h_9_PROLOG
#define UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_RPC_WRAPPERS \
	UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_INCLASS \
	UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_PRIVATE_PROPERTY_OFFSET \
	UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_SPARSE_DATA \
	UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_INCLASS_NO_PURE_DECLS \
	UnrealClient_Source_UnrealClient_Login_LoginUI_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALCLIENT_API UClass* StaticClass<class ULoginUI>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UnrealClient_Source_UnrealClient_Login_LoginUI_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS