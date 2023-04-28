// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "CharAttributes.generated.h"

/**
 * 
 */

 // Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, float, CurrentValue, float, MaxValue);

UCLASS()
class GRAPPLINHOOKZ_API UCharAttributes : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UCharAttributes();

	UPROPERTY(BlueprintAssignable, Category = "MyAttributeSet")
	FOnHealthChanged OnHealthChanged;

	UPROPERTY(ReplicatedUsing = OnRep_Health, BlueprintReadOnly, Category = "AttributeSet")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UCharAttributes, Health)

protected:
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldValue);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
