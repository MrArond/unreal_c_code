#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TimerHud.generated.h"

UCLASS()
class OBSTACLEASSAULT_API ATimerHud : public AHUD
{
    GENERATED_BODY()

public:
    virtual void DrawHUD() override;
};
