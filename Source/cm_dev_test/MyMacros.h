#pragma once

// Macros to prevent repetetive long strings of code

#include "DrawDebugHelpers.h"
#include "Logging/StructuredLog.h"

// Macro to print to log with timestamp and prefix
#define LOG(FormatString, ...) \
UE_LOGFMT(LogTemp, Warning, "{0} " FormatString, \
*FDateTime::Now().ToString(TEXT("[DESIGN] %h:%m:%S%a -")), ##__VA_ARGS__)

// Macro to print text to screen
// Replaces   GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"))
#define PRINT(DebugMessage, ...){ GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::Printf(TEXT(DebugMessage)));}
#define PRINTERR(DebugMessage, ...){ GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT(DebugMessage)));}

// Macro to print to screen which ALSO takes argument to allow things like printing variables / function names
#define PRINTARGS(DebugMessage, ...){ GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, FString::Printf(TEXT(DebugMessage), __VA_ARGS__));}

// Macros to draw centered sphere which only draw if a valid world object is provided (one persistent, 1 not)
#define SPHERE(Center) if (GetWorld()) DrawDebugSphere(GetWorld(), Center, 20, 16, FColor::Blue, true);
#define SPHERE_TICK(Center) if (GetWorld()) DrawDebugSphere(GetWorld(), Center, 20, 16, FColor::Green, false);

// Same as above but for LINE
#define LINE(LineStart, LineEnd) if (GetWorld()) DrawDebugLine(GetWorld(), LineStart, LineEnd, FColor::Blue, true);
#define LINE_TICK(LineStart, LineEnd) if (GetWorld()) DrawDebugLine(GetWorld(), LineStart, LineEnd, FColor::Green, false);