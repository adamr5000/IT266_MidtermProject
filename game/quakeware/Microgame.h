// Added for QuakeWare mod (amr48)

#ifndef __GAME_MICROGAME_H__
#define __GAME_MICROGAME_H__

class idMicrogame : public idEntity {
public:

	enum MicrogameContext { COMBAT, NONCOMBAT, NEUTRAL };
	enum TriggerTiming { BEFORE_INSTANCE, START_OF_INSTANCE, AFTER_INSTANCE, AFTER_INSTANCE_TIMED };

	idMicrogame( ) {

	}

	void set_taskTimer(float tt) {
		taskTimer = tt;
	}

	float get_taskTimer() {
		return taskTimer;
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

	float	taskTimer;		// How long does the user have to complete the task?
	
};

#endif /* !__GAME_MICROGAME_H__ */
