#ifndef FSM_H_
#define FSM_H_
//no entiendo esta linea
typedef struct fsm_ fsm_t;
//no entiendo esta linea
typedef int (*fsm_input_func_t) (fsm_t*);
typedef void (*fsm_output_func_t) (fsm_t*);

// la t y no la t
typedef struct fsm_trans_ {
	int orig_state;
	fsm_input_func_t in;
	int dest_state;
	fsm_output_func_t  out;
} fsm_trans_t;

typedef struct fsm_ {
	int current_state;
	fsm_trans_t* tt;
}fsm_t;

fsm_t* fsm_new(fsm_trans_t* tt);
int fsm_delete(fsm_t* fsm);

void fsm_fire(fsm_t* fsm);


#endif /* FSM_H_ */
