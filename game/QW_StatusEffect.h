// Added for QuakeWare mod (amr48)

#ifndef __GAME_STATUSEFFECT_H__
#define __GAME_STATUSEFFECT_H__

class StatusEffect : public idEntity {
public:

	enum StatusEffectType { BUFF, DEBUFF };
	enum TriggerTiming { BEFORE_INSTANCE, START_OF_INSTANCE, AFTER_INSTANCE, AFTER_INSTANCE_TIMED };

	StatusEffect(int se_id, StatusEffectType se_type, TriggerTiming s_timing = AFTER_INSTANCE, TriggerTiming e_timing = BEFORE_INSTANCE) {
		id = se_id;
		type = se_type;
		startTiming = s_timing;
		endTiming = e_timing;
	}

	void set_triggerTimer(float tt) {
		triggerTimer = tt;
	}

	float get_triggerTimer() {
		return triggerTimer;
	}

	void					Spawn( void );

	void					Save( idSaveGame *savefile ) const;
	void					Restore( idRestoreGame *savefile );

	virtual void			Think( void );

	/*virtual renderView_t *	GetRenderView();
	virtual void			Killed( idEntity *inflictor, idEntity *attacker, int damage, const idVec3 &dir, int location );
	virtual bool			Pain( idEntity *inflictor, idEntity *attacker, int damage, const idVec3 &dir, int location );
	virtual void			Present( void );*/

private:

	int					id;
	StatusEffectType	type;			// What type of status effect this is (buff/reward or debuff/penalty)
	
	TriggerTiming		startTiming;	// When this change should take effect (e.g. apply it right after a microgame ends)
	TriggerTiming		endTiming;		// When the change should end (e.g. remove it right before a microgame starts)
	float				triggerTimer;	// If the TriggerTiming is AFTER_INSTANCE_TIMED, then this long must elapse before
										// the (de)buff is added or removed
	
};

#endif /* !__GAME_STATUSEFFECT_H__ */
