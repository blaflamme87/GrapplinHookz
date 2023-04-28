// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityCharacter.h"
#include "AbilitySystemComponent.h"

// Sets default values
AAbilityCharacter::AAbilityCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create ability system component, and set it to be updated on tick
	AbilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComp->SetIsReplicated(true);
	AbilitySystemComp->SetReplicationMode(EGameplayEffectReplicationMode::Full);

	CharAttributes = CreateDefaultSubobject<UCharAttributes>("CharAttributes");
}

UAbilitySystemComponent* AAbilityCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

// Called when the game starts or when spawned
void AAbilityCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbilityCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAbilityCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAbilityCharacter::GrantAbilities(TArray<TSubclassOf<UGameplayAbility>> Abilities)
{

	if (!AbilitySystemComp) { return; }
	// Grant each ability in the array to the character
	for (TSubclassOf<UGameplayAbility> AbilityClass : Abilities)
	{
		if (HasAuthority() && AbilityClass)
		{
			AbilitySystemComp->GiveAbility(FGameplayAbilitySpec(AbilityClass, 1, 0, this));
		}
		AbilitySystemComp->InitAbilityActorInfo(this, this);
	}
	
	
}

