#include "TimerHud.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"
#include "Engine/Engine.h"

void ATimerHud::DrawHUD()
{
    Super::DrawHUD();

    if (Canvas == nullptr)
        return;

    float TimeSeconds = GetWorld()->GetTimeSeconds();
    FString TimerText = FString::Printf(TEXT("Czas: %.2f s"), TimeSeconds);
    FVector2D ScreenPosition(50, 50);

    // Pobierz domyślny duży font Unreal Engine
    UFont* Font = GEngine->GetLargeFont();

    Canvas->SetDrawColor(FColor::White);
    Canvas->DrawText(Font, TimerText, ScreenPosition.X, ScreenPosition.Y, 1.f, 1.f, FFontRenderInfo());
}
