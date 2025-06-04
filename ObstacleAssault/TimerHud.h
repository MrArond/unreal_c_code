#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TimerHUD.generated.h"

UCLASS()
class OBSTACLEASSAULT_API ATimerHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATimerHUD();

protected:
	virtual void DrawHUD() override;

private:
	float TimeElapsed;
	bool bIsTimePaused; // Flaga do zatrzymania czasu

public:
	// Funkcja do wstrzymywania czasu
	void PauseTime(bool bPause);
};
