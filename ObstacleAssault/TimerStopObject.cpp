#include "TimerStopObject.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerHUD.h"
#include "Engine/World.h"

ATimerStopObject::ATimerStopObject()
{
	PrimaryActorTick.bCanEverTick = true;

	// Tworzymy komponent kolizji i przypisujemy go do zmiennej
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	RootComponent = CollisionBox;

	// Rejestrujemy funkcję wywoływaną podczas kolizji
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ATimerStopObject::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ATimerStopObject::OnOverlapEnd);

	// Inicjalizujemy flagę na false, ponieważ gracz nie jest jeszcze w hitboxie
	bIsInHitbox = false;
}

void ATimerStopObject::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
									   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
									   const FHitResult& SweepResult)
{
	// Sprawdzamy, czy to gracz, a nie inny obiekt
	if (OtherActor && OtherActor != this)
	{
		// Zatrzymujemy czas w HUD, gdy gracz wchodzi w hitbox
		ATimerHUD* MyHUD = Cast<ATimerHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
		if (MyHUD)
		{
			MyHUD->PauseTime(true); // Zatrzymanie czasu w HUD
		}

		// Ustawiamy flagę, że gracz jest w hitboxie
		bIsInHitbox = true;
	}
}

void ATimerStopObject::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
									 class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	// Jeśli to gracz (a nie inny obiekt), wznawiamy czas
	if (OtherActor && OtherActor != this)
	{
		// Wznawiamy czas w HUD, gdy gracz opuści hitbox
		ATimerHUD* MyHUD = Cast<ATimerHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
		if (MyHUD)
		{
			MyHUD->PauseTime(false); // Wznowienie czasu w HUD
		}

		// Ustawiamy flagę, że gracz opuścił hitbox
		bIsInHitbox = false;
	}
}

void ATimerStopObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
