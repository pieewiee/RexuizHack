#include "pch.h"
#include "aimbot.h"


bool Aimbot::IsValidEnt(PlayerPos* PlayerPos)
{
    if (PlayerPos->Position.x != 0 and PlayerPos->Position.y != 0)
    {
        return true;
    }
    return false;
}


vec3 AimbotSubtract(vec3 src, vec3 dst)
{
    vec3 diff;
    diff.x = src.x - dst.x;
    diff.y = src.y - dst.y;
    diff.z = src.z - dst.z;
    return diff;
}

float AimbotMagnitude(vec3 vec)
{
    return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

float AimbotDistance(vec3 src, vec3 dst)
{
    vec3 diff = AimbotSubtract(src, dst);
    return AimbotMagnitude(diff);
}

vec3 CalcAngle(vec3 Source, vec3 Direction)
{
    vec3 Angle;
    vec3 NewAngle;

    Angle.x = Direction.x - Source.x;
    Angle.y = Direction.y - Source.y;
    Angle.z = Direction.z - Source.z;

    float Magnitude = sqrt(Angle.x * Angle.x + Angle.y * Angle.y + Angle.z * Angle.z);

    NewAngle.x = (float)atan2(Angle.y, Angle.x) * 180.0 / PI;
    NewAngle.y = -atan2(Angle.z, Magnitude) * 180.0 / PI;
    NewAngle.z = 0;

    return NewAngle;
}
vec3 ClampAngle(vec3& angle) {
    if (angle.x > 89.0f) angle.x -= 180.0f;
    if (angle.x < -89.0f) angle.x += 180.0f;

    while (angle.y > 180) angle.y -= 360.f;
    while (angle.y < -180) angle.y += 360.f;
    return angle;
}


vec3 Aimbot::GetBestTarget()
{
    float oldDistance = FLT_MAX;
    float newDistance = 0;
    int check = 0;

    vec3 target;

    for (int i = 0; i < (numOfPlayers); i++)
    {

        Player* player = players->Player[i];
        PlayerPos* playerPos = playersPos->PlayerPos[i];

        if (IsValidEnt(playerPos))
        {

            float PlayerDistance = localPlayer->LocalPlayer->position.Distance(playerPos->Position);

            if (PlayerDistance > 100)
            {
                vec3 angleTo = CalcAngle(localPlayer->LocalPlayer->position, playerPos->Position);         
                vec3 swappedangle = { viewangle->viewangle.y, viewangle->viewangle.x, viewangle->viewangle.z };

                newDistance = AimbotDistance(swappedangle, angleTo);

                if (newDistance < oldDistance && newDistance < 50)
                {
                   
                    oldDistance = newDistance;
                    target = angleTo;
                    check = 1;
                }
            }
        }

    }
    if (check == 1)
    {
        return target;
    }
    else {
        vec3 none = { 0,0,1 };
        return none;
    }
    
}

void Aimbot::aim()
{

    vec3 target = GetBestTarget();

        if (target.z != 1)
        {
            viewangle->viewangle.x = target.y;
            viewangle->viewangle.y = target.x;
        }



}


