#pragma once
DWORD64 automatic[]
{
	1545779598, // AK - 47;
	-1758372725, // Томсон
	1796682209, // SMG
	-1812555177,// LR - 300
	1318558775, // MP5
	-2069578888, // M249
	884424049,
	884424049, // Блочка
	1443579727, //лук
	-1214542497,
	1914691295,
	-765183617,
	1103488722,

};

DWORD64 bow[]
{
	1443579727, //лук
	1443579727, //лук
};

DWORD64 sniper[]
{
	-778367295, // L96
	1588298435, // Болт
	1443579727, // лук
	884424049, // Блочка
	1443579727, //лук
	-1367281941,
	795371088,
	-765183617
	- 75944661,
	-41440462,
	1965232394,
	1914691295,
};

DWORD64 shootgun[]
{
	-1367281941,
	795371088,
	-765183617
	- 75944661,
	-41440462,
	1443579727, //лук
	1914691295,
};

DWORD64 semiautomatic[]{
	-904863145, // Берданка 
	818877484, // Пэшка
	-852563019, // берета
	1373971859, // Питон
	649912614, // револьвер
	28201841, // M39
	1953903201, // Гвоздомёт
	-1123473824, // Гранатомёт
	-1367281941,
	795371088,
	-765183617
	- 75944661,
	-41440462,
	884424049, // Блочка
	1443579727, //лук
	1914691295,
	1965232394,
};

DWORD64 meele[]{

	-1966748496, 2040726127, -194509282, 1540934679, 1814288539, 1491189398, 1602646136, -1137865085, 1090916276, -1978999529, 1326180354, 1488979457, 171931394, -1583967946, 200773292, -262590403, -1252059217, 795236088, -196667575, -1506397857, -1302129395, 963906841, 1104520648, -1780802565, -2069578888
};

//script.json
#define oDebugfix 49817960 // ConVar_Client_c*
#define oConVar 49981568 // ConVar_Graphics_c*
#define BaseGameMode 50007568 // System_Collections_Generic_List_BaseGameMode__c*
#define BaseGameMode_c 49752312 // BaseGameMode_c*
#define oBasePlayer 49755432 // BasePlayer_c*
#define oTOD_Sky_c 49912688 // TOD_Sky_c*
#define oConVar_Admin_c 50276136 // ConVar_Admin_c*
#define oMainCamera 50149256 // MainCamera_c*

//dump.cs
#define bodyRotation 0x2C // private Quaternion bodyRotation; class PlayerInput : EntityComponent<BasePlayer>
#define headRotation 0x48 // private Quaternion headRotation; class PlayerInput : EntityComponent<BasePlayer>
#define oPlayerFlags 0x740 // public BasePlayer.PlayerFlags playerFlags; class BasePlayer : BaseCombatEntity,
#define oPlayerName 0x7A0 // protected string _displayName; class BasePlayer : BaseCombatEntity,
#define oPlayerHealth 0x23C // protected float _health; class BaseCombatEntity : BaseEntity
#define oClientTeam 0x638 // public PlayerTeam clientTeam; class BasePlayer : BaseCombatEntity,
#define oLifestate 0x234 // public BaseCombatEntity.LifeState lifestate; class BaseCombatEntity : BaseEntity
#define oSteamID 0x788 // public ulong userID; class BasePlayer : BaseCombatEntity,
#define oPlayerInventory 0x750 // public PlayerInventory inventory; class BasePlayer : BaseCombatEntity,
#define oSkinType 0x16C // public int skinType; class PlayerModel : ListComponent<PlayerModel>,
#define oSkinSetCollection 0x140 // public SkinSetCollection MaleSkin; class PlayerModel : ListComponent<PlayerModel>,
#define oActiveUID 0x668 // private ItemId clActiveItem; class BasePlayer : BaseCombatEntity,
#define oClothingAccuracyBonus 0x81C // public float clothingAccuracyBonus; class BasePlayer : BaseCombatEntity,
#define oJumpTime 0xD0 // private float jumpTime; class PlayerWalkMovement : BaseMovement
#define oLandTime 0xD4 // private float landTime; class PlayerWalkMovement : BaseMovement
#define oGroundTime 0xCC //private private float groundTime; class PlayerWalkMovement : BaseMovement
#define oAimSway 0x2D8 // public float aimSway; class BaseProjectile : AttackEntity
#define oAimSwaySpeed 0x2DC // public float aimSwaySpeed; class BaseProjectile : AttackEntity
#define oDeployDelay 0x1F8 // public float deployDelay; class AttackEntity : HeldEntity
#define oStringHoldDurationMax 0x3B8 // public float stringHoldDurationMax; class CompoundBowWeapon : BowWeapon
#define oStringBonusDamage 0x3BC // public float stringBonusDamage; class CompoundBowWeapon : BowWeapon
#define oMovementPenaltyRampUpTime 0x3C8 // public float movementPenaltyRampUpTime; class CompoundBowWeapon : BowWeapon
#define oCreatedProjectiles 0x398 // private List<Projectile> createdProjectiles; class BaseProjectile : AttackEntity
#define oThickness 0x2C // public float thickness; class Projectile : BaseMonoBehaviour
#define oPlayerEyes 0x748 // public PlayerEyes eyes; class BasePlayer : BaseCombatEntity,
#define oWasFalling 0x148 // private bool wasFalling; class PlayerWalkMovement : BaseMovement
#define oMovement 0x550 // public BaseMovement movement; class BasePlayer : BaseCombatEntity,
#define oPreviousVelocity 0xE4 // private Vector3 previousVelocity; class PlayerWalkMovement : BaseMovement
#define oGroundTime 0xCC // private float groundTime; class PlayerWalkMovement : BaseMovement
#define oAimconeCurveScale 0x60 // public float aimconeCurveScale; class RecoilProperties : ScriptableObject
#define oHeld 0xA8 // private EntityRef heldEntity; class Item // TypeDefIndex:
#define oStancePenalty 0x348 // private float stancePenalty; class BaseProjectile : AttackEntity
#define oAimconePenalty 0x34C // private float aimconePenalty; class BaseProjectile : AttackEntity
#define oHipAimCone 0x2F4 // public float hipAimCone; class BaseProjectile : AttackEntity
#define oAimCone 0x2F0 // public float aimCone; class BaseProjectile : AttackEntity
#define oAimconePenaltyPerShot 0x2F8 // public float aimconePenaltyPerShot; class BaseProjectile : AttackEntity
#define oSuccessFraction 0x3A0 // public float successFraction; class FlintStrikeWeapon : BaseProjectile
#define oCurrentBurstOffset 0x388 // private int currentBurst; class BaseProjectile : AttackEntity
#define oRepeatDelay 0x1FC // public float repeatDelay; class AttackEntity : HeldEntity
#define odisplayname 0x28 // public Translate.Phrase displayName; class ItemDefinition : MonoBehaviour
#define oGrounded 0x140 // private bool grounded; class PlayerWalkMovement : BaseMovement
#define oGravityMultiplierSwimming 0x88 // public float gravityMultiplierSwimming; class PlayerWalkMovement : BaseMovement
#define oClothingBlocksAiming 0x810 // public bool clothingBlocksAiming; class BasePlayer : BaseCombatEntity,
#define oCamspeed 0x3C // private static float _camspeed; class Client : ConsoleSystem
#define oCamlerp 0x30 // public static float camlerp; class Client : ConsoleSystem
#define oAuto 0x290 // public bool automatic; class BaseProjectile : AttackEntity
#define oShortname 0x20 // public string shortname; class ItemDefinition : MonoBehaviour
#define oPlayerMovement 0x550 // public BaseMovement movement; class BasePlayer : BaseCombatEntity,
#define oGravityMultiplier 0x84 // public float gravityMultiplier; class PlayerWalkMovement : BaseMovement
#define oGroundAngleNew 0xC8 // private float groundAngleNew; class PlayerWalkMovement : BaseMovement
#define oGroundAngle 0xC4 // private float groundAngle; class PlayerWalkMovement : BaseMovement
#define oRecoilProperties 0x2E0 // public RecoilProperties recoil; class BaseProjectile : AttackEntity
#define oRecoilMinYaw 0x18 // public float recoilYawMin; class RecoilProperties : ScriptableObject
#define oRecoilMaxYaw 0x1C // public float recoilYawMax; class RecoilProperties : ScriptableObject
#define oRecoilMinPitch 0x20 // public float recoilPitchMin; class RecoilProperties : ScriptableObject
#define oRecoilMaxPitch 0x24 // public float recoilPitchMax; class RecoilProperties : ScriptableObject
#define oPlayerModel 0x528 // public PlayerModel playerModel; class BasePlayer : BaseCombatEntity,
#define oVisible 0x228 // internal bool visible; class PlayerModel : ListComponent<PlayerModel>,
#define oModelState 0x698 // public ModelState modelState; class BasePlayer : BaseCombatEntity,
#define oPlayerInput 0x548 // public PlayerInput input; class BasePlayer : BaseCombatEntity,
#define oBodyAngles 0x3C // private Vector3 bodyAngles; class PlayerInput : EntityComponent<BasePlayer>
#define oItemDefinition 0x18 // public ItemDefinition info; class Item // TypeDefIndex:
#define oItemid 0x18 // public int itemid; class ItemDefinition : MonoBehaviour
#define oAttackReady 0x3A0 // protected bool attackReady; class BowWeapon : BaseProjectile
#define oArrowBack 0x3A4 // private float arrowBack; class BowWeapon : BaseProjectile
#define oBlockSprintOnAttack 0x299 // public bool blockSprintOnAttack; class BaseMelee : AttackEntity
#define oonlyThrowAsProjectile 0x2D3 // public bool onlyThrowAsProjectile; class BaseMelee : AttackEntity
#define othrowReady 0x2D0 // private bool throwReady; class BaseMelee : AttackEntity
#define oAttackRadius 0x294 // public float attackRadius; class BaseMelee : AttackEntity
#define omaxDistance 0x290 // public float maxDistance; class BaseMelee : AttackEntity
#define groundAngle 0xC4 // private float groundAngle; class PlayerWalkMovement : BaseMovement
#define groundAngleNew 0xC8 // private float groundAngleNew; class PlayerWalkMovement : BaseMovement
#define oFlagOnGround 4 // public const ModelState.Flag OnGround =; class PlayerTick : IDisposable,
#define oDidSparkThisFrame 0x3B0 // private bool _didSparkThisFrame; class FlintStrikeWeapon : BaseProjectile
