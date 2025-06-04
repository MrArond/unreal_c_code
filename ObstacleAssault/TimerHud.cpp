#include "TimerHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"
#include "Engine/Engine.h"

ATimerHUD::ATimerHUD()
{
	TimeElapsed = 0.0f;
	bIsTimePaused = false;
}

void ATimerHUD::DrawHUD()
{
	Super::DrawHUD();

	if (!bIsTimePaused)
	{
		TimeElapsed += GetWorld()->GetDeltaSeconds(); // Liczymy czas, jeśli nie jest wstrzymany
	}

	FString TimeText = FString::Printf(TEXT("Time: %.2f"), TimeElapsed);

	FVector2D ScreenPosition(50, 50);

	UFont* Font = GEngine->GetLargeFont();

	Canvas->SetDrawColor(FColor::Black);
	Canvas->DrawText(Font, TimeText, ScreenPosition.X, ScreenPosition.Y, 1.f, 1.f, FFontRenderInfo());
}

void ATimerHUD::PauseTime(bool bPause)
{
	bIsTimePaused = bPause;
}
