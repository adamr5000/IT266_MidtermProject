// Added for QuakeWare mod (amr48)

#ifndef __GAME_QUAKEWARECONTROLLER_H__
#define __GAME_QUAKEWARECONTROLLER_H__

class idQuakeWareController : public idEntity {
public:

	//enum StatusEffectType { BUFF, DEBUFF };
	//enum TriggerTiming { BEFORE_INSTANCE, START_OF_INSTANCE, AFTER_INSTANCE, AFTER_INSTANCE_TIMED };

	idQuakeWareController() {
		this->statusEffectsCount = 0;
	}

	void					AddNewStatusEffect(idStatusEffect *ptr);

	void					Spawn( void );

	void					Save( idSaveGame *savefile ) const;
	void					Restore( idRestoreGame *savefile );

	virtual void			Think( void );

private:

	// The array stores pointers to every status effect object that can be instantiated.
	// The counter starts at 0 and increments every time a status effect is added.
	static const int MAX_TYPES_OF_STATUS_EFFECTS = 20;
	static int statusEffectsCount;
	static idStatusEffect *allStatusEffects[MAX_TYPES_OF_STATUS_EFFECTS];

	
};

#endif /* !__GAME_QUAKEWARECONTROLLER_H__ */
