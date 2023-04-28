// Fill out your copyright notice in the Description page of Project Settings.


#include "CharAttributes.h"
#include "Net/UnrealNetwork.h"

void UCharAttributes::OnRep_Health(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharAttributes, Health, OldValue);
}

void UCharAttributes::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UCharAttributes, Health, COND_None, REPNOTIFY_Always);
}

UCharAttributes::UCharAttributes()
{
	Health.SetBaseValue(100.f);
}