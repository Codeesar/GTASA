#pragma once

const int NUMBER_OF_VECTORS_FOR_AVERAGE=2;
#define CAM_NUM_TARGET_HISTORY          4

class CVehicle;

class CCam
{
public:
	void CacheLastSettingsDWCineyCam();
	//* DoAverageOnVector(CVector const&)
	//* DoCamBump(float, float)
	void Finalise_DW_CineyCams(CVector*, CVector*, float, float, float, float);
	//* GetBoatLook_L_R_HeightOffset(float&)
	void GetCoreDataForDWCineyCamMode(CEntity** targetEntity, CVehicle** targetVehicle, CVector* targetPos, CVector* dwCamLastPos, CVector* at, CVector* right, CVector* top, CVector* linearVelocity, float* linearSpeed, CVector* angularVelocity, float* angularSpeed, CColSphere* colSphere);
	//* GetLookAlongGroundPos(CEntity*, CPed*, CVector&, CVector&)
	//* GetLookFromLampPostPos(CEntity*, CPed*, CVector&, CVector&)
	//* GetLookOverShoulderPos(CEntity*, CPed*, CVector&, CVector&)
	void GetVectorsReadyForRW();
	//* GetWeaponFirstPersonOn()
	//* Get_TwoPlayer_AimVector(CVector&)
	//* Init()
	//* IsTargetInWater(CVector const&)
	//* IsTimeToExitThisDWCineyCamMode(int, CVector*, CVector*, float, bool)
	//* KeepTrackOfTheSpeed(CVector const&, CVector const&, CVector const&, float const&, float const&, float const&)
	//* LookBehind()
	//* LookLeft()
	//* LookRight(bool)
	void Process();
	//* ProcessArrestCamOne()
	//* ProcessArrestCamTwo()
	//* ProcessDWBustedCam1(CPed*, bool)
	//* ProcessPedsDeadBaby()
	//* Process_1rstPersonPedOnPC(CVector const&, float, float, float)
	//* Process_1stPerson(CVector const&, float, float, float)
	//* Process_AimWeapon(CVector const&, float, float, float)
	//* Process_AttachedCam()
	//* Process_BehindCar(CVector const&, float, float, float)
	//* Process_Cam_TwoPlayer()
	//* Process_Cam_TwoPlayer_CalcSource(float, CVector*, CVector*, CVector*)
	//* Process_Cam_TwoPlayer_InCarAndShooting()
	//* Process_Cam_TwoPlayer_Separate_Cars()
	//* Process_Cam_TwoPlayer_Separate_Cars_TopDown()
	//* Process_Cam_TwoPlayer_TestLOSs(CVector)
	//* Process_DW_BirdyCam(bool)
	//* Process_DW_CamManCam(bool)
	//* Process_DW_DogFightCam(bool)
	//* Process_DW_FishCam(bool)
	//* Process_DW_HeliChaseCam(bool)
	//* Process_DW_PlaneCam1(bool)
	//* Process_DW_PlaneCam2(bool)
	//* Process_DW_PlaneCam3(bool)
	//* Process_DW_PlaneSpotterCam(bool)
	//* Process_Editor(CVector const&, float, float, float)
	//* Process_Fixed(CVector const&, float, float, float)
	//* Process_FlyBy(CVector const&, float, float, float)
	//* Process_FollowCar_SA(CVector const&, float, float, float, bool)
	//* Process_FollowPed(CVector const&, float, float, float)
	//* Process_FollowPedWithMouse(CVector const&, float, float, float)
	//* Process_FollowPed_SA(CVector const&, float, float, float, bool)
	//* Process_M16_1stPerson(CVector const&, float, float, float)
	void Process_Rocket(const CVector& a2, float a3, float a4, float a5, bool a6);
	void Process_SpecialFixedForSyphon(const CVector&, float, float, float);
	//* Process_WheelCam(CVector const&, float, float, float)
	//* RotCamIfInFrontCar(CVector const&, float)
	bool Using3rdPersonMouseCam();
private:
    bool    bBelowMinDist; //used for follow ped mode
    bool    bBehindPlayerDesired; //used for follow ped mode
    bool    m_bCamLookingAtVector;
    bool    m_bCollisionChecksOn;
    bool    m_bFixingBeta; //used for camera on a string // 4
    bool    m_bTheHeightFixerVehicleIsATrain;
    bool    LookBehindCamWasInFront;
    bool    LookingBehind;
    bool    LookingLeft; // 8
    bool    LookingRight;
    bool    ResetStatics; //for interpolation type stuff to work
    bool    Rotating;

    short   Mode;                   // CameraMode  // 12
    unsigned int  m_uiFinishTime; // 14
    
    int     m_iDoCollisionChecksOnFrameNum; // 18
    int     m_iDoCollisionCheckEveryNumOfFrames;
    int     m_iFrameNumWereAt;
    int     m_iRunningVectorArrayPos; // 32
    int     m_iRunningVectorCounter;
    int     DirectionWasLooking; // 40
    
    float   f_max_role_angle; //=DEGTORAD(5.0f);    // 44
    float   f_Roll; //used for adding a slight roll to the camera in the
    float   f_rollSpeed; //camera on a string mode
    float   m_fSyphonModeTargetZOffSet; // 56
    float   m_fAmountFractionObscured;
    float   m_fAlphaSpeedOverOneFrame; // 64
    float   m_fBetaSpeedOverOneFrame;
    float   m_fBufferedTargetBeta; // 72
    float   m_fBufferedTargetOrientation;
    float   m_fBufferedTargetOrientationSpeed; // 80
    float   m_fCamBufferedHeight;
    float   m_fCamBufferedHeightSpeed;
    float   m_fCloseInPedHeightOffset; // 92
    float   m_fCloseInPedHeightOffsetSpeed;
    float   m_fCloseInCarHeightOffset;
    float   m_fCloseInCarHeightOffsetSpeed; // 104
    float   m_fDimensionOfHighestNearCar;
    float   m_fDistanceBeforeChanges; // 112
    float   m_fFovSpeedOverOneFrame;
    float   m_fMinDistAwayFromCamWhenInterPolating; // 120
    float   m_fPedBetweenCameraHeightOffset;
    float   m_fPlayerInFrontSyphonAngleOffSet; // 128
    float   m_fRadiusForDead;
    float   m_fRealGroundDist; //used for follow ped mode // 136
    float   m_fTargetBeta;
    float   m_fTimeElapsedFloat;
    float   m_fTilt; // 148
    float   m_fTiltSpeed; // 152

    float   m_fTransitionBeta; // 156
    float   m_fTrueBeta; // 160
    float   m_fTrueAlpha; // 164
    float   m_fInitialPlayerOrientation; //used for first person // 168

    float   m_fVerticalAngle; // alpha // 172
    float   AlphaSpeed; // 176
    float   FOV; // 180
    float   FOVSpeed; // 184
    float   m_fHorizontalAngle; // beta // 188
    float   BetaSpeed; // 192
    float   Distance; // 196
    float   DistanceSpeed;
    float   CA_MIN_DISTANCE; // 204
    float   CA_MAX_DISTANCE;
    float   SpeedVar;
    float   m_fCameraHeightMultiplier; //used by TwoPlayer_Separate_Cars_TopDown // 216
    
    // ped onfoot zoom distance
    float m_fTargetZoomGroundOne; // 220
    float m_fTargetZoomGroundTwo;
    float m_fTargetZoomGroundThree; // 228
    // ped onfoot alpha angle offset
    float m_fTargetZoomOneZExtra;
    float m_fTargetZoomTwoZExtra;
    float m_fTargetZoomTwoInteriorZExtra; //extra one for interior
    float m_fTargetZoomThreeZExtra; // 244
    
    float m_fTargetZoomZCloseIn; // 248
    float m_fMinRealGroundDist;
    float m_fTargetCloseInDist;

    // For targetting in cooperative mode.
    float   Beta_Targeting; // 260
    float   X_Targetting, Y_Targetting;
    int CarWeAreFocussingOn; //which car is closer to the camera in 2 player cooperative mode with separate cars. // 272
    float   CarWeAreFocussingOnI; //interpolated version
    
    float m_fCamBumpedHorz; // 280
    float m_fCamBumpedVert;
    int m_nCamBumpedTime; // 288
    static int CAM_BUMPED_SWING_PERIOD;
    static int CAM_BUMPED_END_TIME;
    static float CAM_BUMPED_DAMP_RATE;
    static float CAM_BUMPED_MOVE_MULT;

    CVector m_cvecSourceSpeedOverOneFrame; // 292
    CVector m_cvecTargetSpeedOverOneFrame; // 304
    CVector m_cvecUpOverOneFrame; // 316
    
    CVector m_cvecTargetCoorsForFudgeInter; // 328
    CVector m_cvecCamFixedModeVector; // 340
    CVector m_cvecCamFixedModeSource; // 352
    CVector m_cvecCamFixedModeUpOffSet; // 364
    CVector m_vecLastAboveWaterCamPosition; // 376  //helper for when the player has gone under the water

    CVector m_vecBufferedPlayerBodyOffset; // 388

    // The three vectors that determine this camera for this frame
    CVector Front;  // 400                                          // Direction of looking in
    CVector Source;                                                 // Coors in world space
    CVector SourceBeforeLookBehind; // 424
    CVector Up;                                                     // Just that
    CVector m_arrPreviousVectors[NUMBER_OF_VECTORS_FOR_AVERAGE];    // used to average stuff // 448

    CVector m_aTargetHistoryPos[CAM_NUM_TARGET_HISTORY]; // 472
    DWORD m_nTargetHistoryTime[CAM_NUM_TARGET_HISTORY]; // 520
    DWORD m_nCurrentHistoryPoints; // 536

    CEntity *CamTargetEntity;
public:
    float       m_fCameraDistance; // 544
    float       m_fIdealAlpha;
    float       m_fPlayerVelocity; // 552
    //CVector TempRight;
    class CAutomobile  *m_pLastCarEntered; // So interpolation works
    CPed         *m_pLastPedLookedAt;// So interpolation works 
    bool        m_bFirstPersonRunAboutActive; // 564
};