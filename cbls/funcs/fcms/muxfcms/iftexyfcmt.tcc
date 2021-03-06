/*!
	@file iftexyfcmt.tcc
	@brief The prototype file for IfteXYFcMt template class.
	@details This is the prototype file for IfteXYFcMt template class.
	@author M.A.Hakim Newton hakim.newton@nicta.com.au
	@author Duc Nghia Pham duc-nghia.pham@nicta.com.au
	@date 16.11.2009 QRL NICTA www.nicta.com.au
*/



#ifndef IfteXYFcMtTccIncluded
#define IfteXYFcMtTccIncluded



#include "cbls/funcs/fcms/muxfcmt.tcc"



openKangarooSpace



/*!
	@class IfteXYFcMt
	@brief A template class to represent if-then-else expressions.
	@details This template class represents if-then-else expressions.
*/
template<typename pxt, typename pyt, typename fmt>
class IfteXYFcMt : public MuxFcMt<fmt>
{
	public:

		static Hdl def(Fss const theFss, Hdl const hdlSys, Prm * thePrms);					//!< Definition.
		static Hdl def(Fss const theFss, Hdl const hdlSys,
									Prm const & Cond, Prm const & Then, Prm const & Else);	//!< Definition.

		static IfteXYFcMt<pxt,pyt,fmt> & refm(Hdl const hdlSys, Hdl const hdlFunc);			//!< Reference.
		static IfteXYFcMt<pxt,pyt,fmt> * ptrm(Hdl const hdlSys, Hdl const hdlFunc);			//!< Pointer.
		static IfteXYFcMt<pxt,pyt,fmt> const & refc(Hdl const hdlSys, Hdl const hdlFunc);	//!< Reference.
		static IfteXYFcMt<pxt,pyt,fmt> const * ptrc(Hdl const hdlSys, Hdl const hdlFunc);	//!< Pointer.

		//! @name Casting
		//! @{

		static IfteXYFcMt<pxt,pyt,fmt> const & cast(Term const & theTerm);		//!< Perform casting.
		static IfteXYFcMt<pxt,pyt,fmt> const * cast(Term const * theTerm);		//!< Perform casting.
		static IfteXYFcMt<pxt,pyt,fmt> & cast(Term & theTerm);					//!< Perform casting.
		static IfteXYFcMt<pxt,pyt,fmt> * cast(Term * theTerm);					//!< Perform casting.

		static Bll suit(Term const & theTerm);								//!< Suits casting?
		static Bll suit(Term const * theTerm);								//!< Suits casting?
		static Bll suit(Term & theTerm);									//!< Suits casting?
		static Bll suit(Term * theTerm);									//!< Suits casting?

		//! @}

	private:

		virtual ~IfteXYFcMt();													//!< Destructor.
		IfteXYFcMt(IfteXYFcMt<pxt,pyt,fmt> const & that);						//!< Duplicator.
		IfteXYFcMt(Fss const theFss, Hdl const hdlSys,
									Prm * thePrms, Dim const PrmCount);			//!< Constructor.
		IfteXYFcMt const & operator = (IfteXYFcMt<pxt,pyt,fmt> const & that);	//!< Assigner.

		//! @name Deferment
		//! @{

		#if CompLazy
		void reinitEvalUndoPrms();			//!< Call parameters to list for eval undo.
		void reiterEvalUndoPrms();			//!< Call parameters to relist for eval undo.
		#endif
		#if CompLazyHalf
		virtual void notifyDeferedPrms();	//!< Notify deferment to the parameters.
		virtual void notifyEnforcedPrms();	//!< Notify enforcement to the parameters.
		#endif

		//! @}

		//! @name Postprocessing
		//! @{

		#if ExecUpwdLazy
		void runPostExecAnew();		//!< Run post exection in anew mode.
		void runPostExecIncr();		//!< Run post execuiton in incr mode.
		#endif
		#if SimulUpwd
		void runPostSimulAnew();	//!< Run post simulation in anew mode.
		void runPostSimulIncr();	//!< Run post simulation in incr mode.
		#endif
		#if CompLazy
		void runPostExecBklg();		//!< Run post execuiton in bklg mode.
		#endif

		//! @}

		//! @name Computations
		//! @{

		virtual void compConst();	//!< Compute the term.
		virtual void execAnew();	//!< Execute the term.
		virtual void simulAnew();	//!< Simulate the term.
		virtual void execIncr();	//!< Execute the term.
		virtual void simulIncr();	//!< Simulate the term.
		#if CompLazy
		virtual void execBklg();	//!< Execute the term.
		virtual void emulBklg();	//!< Emulate the term.
		#endif

		//! @}

	private:

		EvalRec<pxt> const * mPxRec;	//!< Cond parameter value.
		EvalRec<pyt> const * mTyRec;	//!< Then parameter value.
		EvalRec<pyt> const * mEyRec;	//!< Else parameter value.
};



/*!
	Whether a term is suitable for casting.
*/
template<typename pxt, typename pyt, typename fmt>
inline Bll IfteXYFcMt<pxt,pyt,fmt>::suit(Term const & theTerm)
{
	WatchError
	return theTerm.TermCls == TermStub< IfteXYFcMt<pxt,pyt,fmt> >::TermCls;
	CatchError
}



/*!
	Whether a term is suitable for casting.
*/
template<typename pxt, typename pyt, typename fmt>
inline Bll IfteXYFcMt<pxt,pyt,fmt>::suit(Term const * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);

	return theTerm->TermCls == TermStub< IfteXYFcMt<pxt,pyt,fmt> >::TermCls;
	CatchError
}


/*!
	Whether a term is suitable for casting.
*/
template<typename pxt, typename pyt, typename fmt>
inline Bll IfteXYFcMt<pxt,pyt,fmt>::suit(Term & theTerm)
{
	WatchError
	return theTerm.TermCls == TermStub< IfteXYFcMt<pxt,pyt,fmt> >::TermCls;
	CatchError
}



/*!
	Whether a term is suitable for casting.
*/
template<typename pxt, typename pyt, typename fmt>
inline Bll IfteXYFcMt<pxt,pyt,fmt>::suit(Term * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);

	return theTerm->TermCls == TermStub< IfteXYFcMt<pxt,pyt,fmt> >::TermCls;
	CatchError
}



/*!
	Perform casting of a term.
*/
template<typename pxt, typename pyt, typename fmt>
inline IfteXYFcMt<pxt,pyt,fmt> const &
IfteXYFcMt<pxt,pyt,fmt>::cast(Term const & theTerm)
{
	WatchError
	Wchk(theTerm.TermCls != TermStub< IfteXYFcMt<pxt,pyt,fmt> >::TermCls) Wtxt(eWrongCls);

	return scast<IfteXYFcMt<pxt,pyt,fmt> const &>(theTerm);
	CatchError
}



/*!
	Perform casting of a term.
*/
template<typename pxt, typename pyt, typename fmt>
inline IfteXYFcMt<pxt,pyt,fmt> const *
IfteXYFcMt<pxt,pyt,fmt>::cast(Term const * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);
	Wchk(theTerm->TermCls != TermStub< IfteXYFcMt<pxt,pyt,fmt> >::TermCls) Wtxt(eWrongCls);

	return scast<IfteXYFcMt<pxt,pyt,fmt> const *>(theTerm);
	CatchError
}



/*!
	Perform casting of a term.
*/
template<typename pxt, typename pyt, typename fmt>
inline IfteXYFcMt<pxt,pyt,fmt> &
IfteXYFcMt<pxt,pyt,fmt>::cast(Term & theTerm)
{
	WatchError
	Wchk(theTerm.TermCls != TermStub< IfteXYFcMt<pxt,pyt,fmt> >::TermCls) Wtxt(eWrongCls);

	return scast<IfteXYFcMt<pxt,pyt,fmt> &>(theTerm);
	CatchError
}



/*!
	Perform casting of a term.
*/
template<typename pxt, typename pyt, typename fmt>
inline IfteXYFcMt<pxt,pyt,fmt> *
IfteXYFcMt<pxt,pyt,fmt>::cast(Term * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);
	Wchk(theTerm->TermCls != TermStub< IfteXYFcMt<pxt,pyt,fmt> >::TermCls) Wtxt(eWrongCls);

	return scast<IfteXYFcMt<pxt,pyt,fmt> *>(theTerm);
	CatchError
}



/*!
	Refer to an if-then-else term.
*/
template<typename pxt, typename pyt, typename fmt>
inline IfteXYFcMt<pxt,pyt,fmt> &
IfteXYFcMt<pxt,pyt,fmt>::refm(Hdl const hdlSys, Hdl const hdlFunc)
{
	WatchError
	return cast(Sys::refm(hdlSys).refmFunc(hdlFunc));
	CatchError
}



/*!
	Point to an if-then-else term.
*/
template<typename pxt, typename pyt, typename fmt>
inline IfteXYFcMt<pxt,pyt,fmt> *
IfteXYFcMt<pxt,pyt,fmt>::ptrm(Hdl const hdlSys, Hdl const hdlFunc)
{
	WatchError
	return cast(Sys::ptrm(hdlSys)->ptrmFunc(hdlFunc));
	CatchError
}



/*!
	Refer to an if-then-else term.
*/
template<typename pxt, typename pyt, typename fmt>
inline IfteXYFcMt<pxt,pyt,fmt> const &
IfteXYFcMt<pxt,pyt,fmt>::refc(Hdl const hdlSys, Hdl const hdlFunc)
{
	WatchError
	return cast(Sys::refc(hdlSys).refcFunc(hdlFunc));
	CatchError
}



/*!
	Point to an if-then-else term.
*/
template<typename pxt, typename pyt, typename fmt>
inline IfteXYFcMt<pxt,pyt,fmt> const *
IfteXYFcMt<pxt,pyt,fmt>::ptrc(Hdl const hdlSys, Hdl const hdlFunc)
{
	WatchError
	return cast(Sys::ptrc(hdlSys)->ptrcFunc(hdlFunc));
	CatchError
}



/*!
	The destructor.
*/
template<typename pxt, typename pyt, typename fmt>
inline IfteXYFcMt<pxt,pyt,fmt>::~IfteXYFcMt()
{
	WatchError
	//	nothing to be done.
	CatchError
}


#if ExecUpwdLazy
/*!
	Run post exection process in anew mode.
*/
template<typename pxt, typename pyt, typename fmt>
inline void IfteXYFcMt<pxt,pyt,fmt>::runPostExecAnew()
{
	WatchError
	#if ExecUpwd
	this->clearExecChgdPrms();
	this->scheduleExecAnewArgs();
	#endif
	#if ExecLazy
	this->clearEvalUndoArgs();
	this->reinitEvalUndoPrms();
	#endif
	CatchError
}
#endif //ExecUpwdLazy


#if ExecUpwdLazy
/*!
	Run post execution process in incr mode.
*/
template<typename pxt, typename pyt, typename fmt>
inline void IfteXYFcMt<pxt,pyt,fmt>::runPostExecIncr()
{
	WatchError
	#if ExecUpwd
	this->clearExecChgdPrms();
	if (this->mMetricRec->PrevDiff(this->mTermSys.ExecClk()))
		this->scheduleExecIncrArgs();
	#endif
	#if ExecLazy
	if (this->mMetricRec->PrevDiff(this->mTermSys.ExecClk()))
		this->notifyEvalUndoArgs();
	this->reiterEvalUndoPrms();
	#endif
	CatchError
}
#endif //ExecUpwdLazy


#if CompLazy
/*!
	Run post execution process in bklg mode.
*/
template<typename pxt, typename pyt, typename fmt>
inline void IfteXYFcMt<pxt,pyt,fmt>::runPostExecBklg()
{
	WatchError
	if (this->mMetricRec->PrevDiff(this->mTermSys.ExecClk()))
		this->notifyEvalUndoArgs();
	this->reiterEvalUndoPrms();
	CatchError
}
#endif //CompLazy



#if SimulUpwd
/*!
	Run post simulation process in anew mode.
*/
template<typename pxt, typename pyt, typename fmt>
inline void IfteXYFcMt<pxt,pyt,fmt>::runPostSimulAnew()
{
	WatchError
	this->clearSimulChgdPrms();
	this->scheduleSimulAnewArgs();
	CatchError
}
#endif //SimulUpwd


#if SimulUpwd
/*!
	Run post simulation process in incr mode.
*/
template<typename pxt, typename pyt, typename fmt>
inline void IfteXYFcMt<pxt,pyt,fmt>::runPostSimulIncr()
{
	WatchError
	this->clearSimulChgdPrms();
	if (this->mMetricRec->NextDiff(this->mTermSys.SimulClk()))
		this->scheduleSimulIncrArgs();
	CatchError
}
#endif //SimulUpwd



/*!
	Define an if-then-else expression.
*/
template<typename pxt, typename pyt, typename fmt>
inline Hdl IfteXYFcMt<pxt,pyt,fmt>::def(Fss const theFss, Hdl const hdlSys,
		Prm const & Cond, Prm const & Then, Prm const & Else)
{
	WatchError
	Prm tPrms[3] = { Cond, Then, Else };
	return def(theFss, hdlSys, tPrms);
	CatchError
}



/*!
	Define an if-then-else expression.
*/
template<typename pxt, typename pyt, typename fmt>
Hdl IfteXYFcMt<pxt,pyt,fmt>::def(Fss const theFss, Hdl const hdlSys, Prm * thePrms)
{
	WatchError
	IfteXYFcMt<pxt,pyt,fmt> * tFcM = new IfteXYFcMt<pxt,pyt,fmt>(theFss, hdlSys, thePrms, 3);
	Hdl const tHdl = tFcM->defSysFunc();
	if (tHdl != InvHdl) { delete tFcM; return tHdl; }

	EvalTbl<pxt> const & tPxtTbl = EvalTbl<pxt>::refc(hdlSys);
	EvalTbl<pyt> const & tPytTbl = EvalTbl<pyt>::refc(hdlSys);
	EvalTbl<fmt> & tFmtTbl = EvalTbl<fmt>::refm(hdlSys);

	b1<Term *,kmm> const & tPrmTerms = tFcM->mPrmTerms;
	b1<Pss,kmm> const & tPrmSpecs = tFcM->mPrmSpecs;

	Loc const tPxLoc = getPxLoc(theFss, tPrmTerms[0], tPrmSpecs[0]);
	tFcM->mPxRec = tPxtTbl.ptrcEvalRec(tPxLoc);

	Loc const tTyLoc = getPyLoc(theFss, tPrmTerms[1], tPrmSpecs[1]);
	tFcM->mTyRec = tPytTbl.ptrcEvalRec(tTyLoc);

	Loc const tEyLoc = getPyLoc(theFss, tPrmTerms[2], tPrmSpecs[2]);
	tFcM->mEyRec = tPytTbl.ptrcEvalRec(tEyLoc);

	tFmtTbl.setEvalRec(tFcM->mMetricRec, tFcM->mMetricLoc);

	tFcM->performCompConst();
	tFcM->defSysRoot();
	return tFcM->TermHdl;
	CatchError
}



/*!
	The constructor.
*/
template<typename pxt, typename pyt, typename fmt>
IfteXYFcMt<pxt,pyt,fmt>::IfteXYFcMt(Fss const theFss, Hdl const hdlSys,
		Prm * thePrms, Dim const PrmCount) :
		MuxFcMt<fmt>(hdlSys, PrmCount)
{
	WatchError
	this->setTermCls(TermStub< IfteXYFcMt<pxt,pyt,fmt> >::TermCls);
	this->setParams(theFss, thePrms, PrmCount, Ordered);
	this->setTermHvl(this->calcTermHvl());
	CatchError
}



/*!
	The duplicator.
*/
template<typename pxt, typename pyt, typename fmt>
IfteXYFcMt<pxt,pyt,fmt>::IfteXYFcMt(IfteXYFcMt<pxt,pyt,fmt> const & that) :
	MuxFcMt<fmt>(that)
{
	WatchError
	Throw(eUndefDuplicator);
	CatchError
}



/*!
	The assigner.
*/
template<typename pxt, typename pyt, typename fmt>
IfteXYFcMt<pxt,pyt,fmt> const & IfteXYFcMt<pxt,pyt,fmt>::operator =
		(IfteXYFcMt<pxt,pyt,fmt> const & that)
{
	WatchError
	Throw(eUndefAssigner);
	CatchError
}



#if CompLazyHalf
/*!
	Notify deferment to the parameters.
*/
template<typename pxt, typename pyt, typename fmt>
void IfteXYFcMt<pxt,pyt,fmt>::notifyDeferedPrms()
{
	WatchError
	Term * const tPrmTerm = this->mPrmTerms[0];
	if (tPrmTerm->computable())	//	not Updatable to exclude vars
		Func::unsetEnforcement(Func::cast(tPrmTerm));

	this->reinitEvalUndoPrms();
	CatchError
}
#endif //CompLazyHalf



#if CompLazyHalf
/*!
	Notify enforcement to the parameters.
*/
template<typename pxt, typename pyt, typename fmt>
void IfteXYFcMt<pxt,pyt,fmt>::notifyEnforcedPrms()
{
	WatchError
	Term * const tPrmTerm = this->mPrmTerms[0];
	if (tPrmTerm->computable())	//	not Updatable to exclude vars
		Func::setEnforcement(Func::cast(tPrmTerm));
	CatchError
}
#endif //CompLazyHalf



#if CompLazy
/*!
	Call parameters to list for eval undo.
*/
template<typename pxt, typename pyt, typename fmt>
void IfteXYFcMt<pxt,pyt,fmt>::reinitEvalUndoPrms()
{
	WatchError
	//	no mode anew mode checking because deferment would happen even
	//	when incr mode and still need this method to run.
	Warn(!this->mEvalUndonePrms, eNullPointer);

	#if CompLazyHalf
	if (this->defered())
	#endif
	{
		Term * const tCondTerm = this->mPrmTerms[0];
		if (tCondTerm->updatable())	//	include vars
			Term::relistEvalUndoArg(tCondTerm, this->mPrmLinks[0]);

		if (tc<pxt,Bll>::iof(mPxRec->CurrData()))
		{
			Term * const tMetricTerm = this->mPrmTerms[1];
			if (tMetricTerm->updatable())	//	include vars
				Term::relistEvalUndoArg(tMetricTerm, this->mPrmLinks[1]);
		}
		else
		{
			Term * const tMetricTerm = this->mPrmTerms[2];
			if (tMetricTerm->updatable())
				Term::relistEvalUndoArg(tMetricTerm, this->mPrmLinks[2]);
		}
	}
	this->mBacklogPrms.sweep(this->mTermSys.ExecClk());
	this->mEvalUndonePrms->sweep(this->mTermSys.ExecClk());
	CatchError
}
#endif //CompLazy



#if CompLazy
/*!
	Call parameters to relist for eval undo.
*/
template<typename pxt, typename pyt, typename fmt>
void IfteXYFcMt<pxt,pyt,fmt>::reiterEvalUndoPrms()
{
	WatchError
	Warn(!this->mTermSys.mskExecMode(IncrProp), eNotExecIncrProp);
	Warn(!this->mEvalUndonePrms, eNullPointer);

	#if CompLazyHalf
	if (this->defered())
	#endif
	{
		Term * const tCondTerm = this->mPrmTerms[0];
		if (tCondTerm->updatable())
			Term::relistEvalUndoArg(tCondTerm, this->mPrmLinks[0]);

		if (tc<pxt,Bll>::iof(mPxRec->CurrData()))
		{
			Term * const tMetricTerm = this->mPrmTerms[1];
			if (tMetricTerm->updatable())
				Term::relistEvalUndoArg(tMetricTerm, this->mPrmLinks[1]);
		}
		else
		{
			Term * const tMetricTerm = this->mPrmTerms[2];
			if (tMetricTerm->updatable())
				Term::relistEvalUndoArg(tMetricTerm, this->mPrmLinks[2]);
		}
	}
	this->mBacklogPrms.sweep(this->mTermSys.ExecClk());
	this->mEvalUndonePrms->sweep(this->mTermSys.ExecClk());
	CatchError
}
#endif //CompLazy


/*!
	Compute the term.
*/
template<typename pxt, typename pyt, typename fmt>
void IfteXYFcMt<pxt,pyt,fmt>::compConst()
{
	WatchError
	if (this->updatable() && !this->mPrmTerms[0]->updatable())
	{
		if (tc<pxt,Bll>::iof(mPxRec->CurrData()))
		{
			if (!this->mPrmTerms[1]->updatable())
				this->setUpdatable(false);
		}
		else
		{
			if (!this->mPrmTerms[2]->updatable())
				this->setUpdatable(false);
		}
	}
	if (!this->updatable())
	{
		if (tc<pxt,Bll>::iof(mPxRec->CurrData()))
			this->mMetricRec->finalise(tc<pyt,fmt>::iof(mTyRec->CurrData()));
		else
			this->mMetricRec->finalise(tc<pyt,fmt>::iof(mEyRec->CurrData()));
	}
	CatchError
}



/*!
	Compute the term in execution mode.
*/
template<typename pxt, typename pyt, typename fmt>
void IfteXYFcMt<pxt,pyt,fmt>::execAnew()
{
	WatchError
	#if ExecDnwd
	Term::performExecAnew(this->mPrmTerms[0]);
	Term::performExecAnew(this->mPrmTerms[1]);
	Term::performExecAnew(this->mPrmTerms[2]);
	#endif

	if (tc<pxt,Bll>::iof(mPxRec->CurrData()))
		this->mMetricRec->initCurr(tc<pyt,fmt>::iof(mTyRec->CurrData()));
	else
		this->mMetricRec->initCurr(tc<pyt,fmt>::iof(mEyRec->CurrData()));
	#if ExecUpwdLazy
	this->runPostExecAnew();
	#endif
	CatchError
}



/*!
	Compute the term in simulation mode.
*/
template<typename pxt, typename pyt, typename fmt>
void IfteXYFcMt<pxt,pyt,fmt>::simulAnew()
{
	WatchError
	#if SimulDnwd
	Term::performSimulAnew(this->mPrmTerms[0]);
	#endif
	if (tc<pxt,Bll>::iof(mPxRec->NextData(this->mTermSys.SimulClk())))
	{
		#if SimulDnwd
		Term::performSimulAnew(this->mPrmTerms[1]);
		#endif
		this->mMetricRec->updtNext(this->mTermSys.SimulClk(),
				tc<pyt,fmt>::iof(mTyRec->NextData(this->mTermSys.SimulClk())));
	}
	else
	{
		#if SimulDnwd
		Term::performSimulAnew(this->mPrmTerms[2]);
		#endif
		this->mMetricRec->updtNext(this->mTermSys.SimulClk(),
				tc<pyt,fmt>::iof(mEyRec->NextData(this->mTermSys.SimulClk())));
	}
	#if SimulUpwd
	this->runPostSimulAnew();
	#endif
	CatchError
}



/*!
	Compute the term in execution mode.
*/
template<typename pxt, typename pyt, typename fmt>
void IfteXYFcMt<pxt,pyt,fmt>::execIncr()
{
	WatchError
	#if ExecUpwd
	if (this->mExecChgdPrms.tagCount())
	{
		Bll tNeedRecomp = this->mExecChgdPrms.tagged(0) &&
				mPxRec->PrevDiff(this->mTermSys.ExecClk());
		if (tc<pxt,Bll>::iof(mPxRec->CurrData()))
		{
			if (tNeedRecomp || (this->mExecChgdPrms.tagged(1) &&
					mTyRec->PrevDiff(this->mTermSys.ExecClk())))
				this->mMetricRec->updtCurr(this->mTermSys.ExecClk(),
						tc<pyt,fmt>::iof(mTyRec->CurrData()));
		}
		else
		{
			if (tNeedRecomp || (this->mExecChgdPrms.tagged(2) &&
					mEyRec->PrevDiff(this->mTermSys.ExecClk())))
				this->mMetricRec->updtCurr(this->mTermSys.ExecClk(),
						tc<pyt,fmt>::iof(mEyRec->CurrData()));
		}
		this->runPostExecIncr();
	}
	#endif	//ExecUpwd
	#if ExecDnwd
	Bll tNeedRecomp = false;
	if (this->needExecCandComp()) this->markCandParams();
	#if CompLazy
	if (!this->backlog())
	{
	#endif	//CompLazy
		if (this->mLblCandPrms.tagged(0))
		{
			Term::performExecIncr(this->mPrmTerms[0]);
			if (mPxRec->PrevDiff(this->mTermSys.ExecClk()))
				tNeedRecomp = true;
		}
		if (tc<pxt,Bll>::iof(mPxRec->CurrData()))
		{
			if (this->mLblCandPrms.tagged(1))
			{
				Term::performExecIncr(this->mPrmTerms[1]);
				if (!tNeedRecomp && mTyRec->PrevDiff(this->mTermSys.ExecClk()))
					tNeedRecomp = true;
			}
			#if CompLazy
			else
			{
				Term::performExecBklg(this->mPrmTerms[1]);
				if (!tNeedRecomp && mTyRec->PrevDiff(this->mTermSys.ExecClk()))
					tNeedRecomp = true;
			}
			#endif

			if (tNeedRecomp)
				this->mMetricRec->updtCurr(this->mTermSys.ExecClk(),
						tc<pyt,fmt>::iof(mTyRec->CurrData()));
			#if !CompLazy
			if (this->mLblCandPrms.tagged(2))	// Required in non-lazy mode.
				Term::performExecIncr(this->mPrmTerms[2]);
			#endif
		}
		else
		{
			if (this->mLblCandPrms.tagged(2))
			{
				Term::performExecIncr(this->mPrmTerms[2]);
				if (!tNeedRecomp && mEyRec->PrevDiff(this->mTermSys.ExecClk()))
					tNeedRecomp = true;
			}
			#if CompLazy
			else
			{
				Term::performExecBklg(this->mPrmTerms[2]);
				if (!tNeedRecomp && mEyRec->PrevDiff(this->mTermSys.ExecClk()))
					tNeedRecomp = true;
			}
			#endif
			if (tNeedRecomp)
				this->mMetricRec->updtCurr(this->mTermSys.ExecClk(),
						tc<pyt,fmt>::iof(mEyRec->CurrData()));
			#if !CompLazy
			if (this->mLblCandPrms.tagged(1))	// Required in non-lazy mode.
				Term::performExecIncr(this->mPrmTerms[1]);
			#endif
		}
	#if CompLazy
	}
	else
	{
		if (this->mLblCandPrms.tagged(0))
		{
			Term::performExecIncr(this->mPrmTerms[0]);
			if (this->mEvalUndonePrms->tagged(0) ||
					mPxRec->PrevDiff(this->mTermSys.ExecClk()))
				tNeedRecomp = true;
		}
		else if (this->mBacklogPrms.tagged(0))
		{
			Term::performExecBklg(this->mPrmTerms[0]);
			if (this->mEvalUndonePrms->tagged(0) ||
					mPxRec->PrevDiff(this->mTermSys.ExecClk()))
				tNeedRecomp = true;
		}
		if (tc<pxt,Bll>::iof(mPxRec->CurrData()))
		{
			if (this->mLblCandPrms.tagged(1))
			{
				Term::performExecIncr(this->mPrmTerms[1]);
				if (!tNeedRecomp && (this->mEvalUndonePrms->tagged(1) ||
						mTyRec->PrevDiff(this->mTermSys.ExecClk())))
					tNeedRecomp = true;
			}
			else //	no backlog checking, param1 is assumed to be defered.
			{
				Term::performExecBklg(this->mPrmTerms[1]);
				if (!tNeedRecomp && (this->mEvalUndonePrms->tagged(1) ||
						mTyRec->PrevDiff(this->mTermSys.ExecClk())))
					tNeedRecomp = true;
			}
			if (tNeedRecomp)
				this->mMetricRec->updtCurr(this->mTermSys.ExecClk(),
						tc<pyt,fmt>::iof(mTyRec->CurrData()));
		}
		else
		{
			if (this->mLblCandPrms.tagged(2))
			{
				Term::performExecIncr(this->mPrmTerms[2]);
				if (!tNeedRecomp && (this->mEvalUndonePrms->tagged(2) ||
						mEyRec->PrevDiff(this->mTermSys.ExecClk())))
					tNeedRecomp = true;
			}
			else //	no backlog checking, param2 is assumed to be defered.
			{
				Term::performExecBklg(this->mPrmTerms[2]);
				if (!tNeedRecomp && (this->mEvalUndonePrms->tagged(2) ||
						mEyRec->PrevDiff(this->mTermSys.ExecClk())))
					tNeedRecomp = true;
			}
			if (tNeedRecomp)
				this->mMetricRec->updtCurr(this->mTermSys.ExecClk(),
						tc<pyt,fmt>::iof(mEyRec->CurrData()));
		}
	}
	this->runPostExecIncr();
	#endif	//CompLazy
	#endif //ExecDnwd
	CatchError
}



#if CompLazy
/*!
	Compute the term in execution mode.
*/
template<typename pxt, typename pyt, typename fmt>
void IfteXYFcMt<pxt,pyt,fmt>::execBklg()
{
	WatchError
	Bll tNeedRecomp = false;
	if (this->mBacklogPrms.tagged(0))
	{
		Term::performExecBklg(this->mPrmTerms[0]);
		if (this->mEvalUndonePrms->tagged(0) ||
				mPxRec->PrevDiff(this->mTermSys.ExecClk()))
			tNeedRecomp = true;
	}
	if (tc<pxt,Bll>::iof(mPxRec->CurrData()))
	{
		Term::performExecBklg(this->mPrmTerms[1]);
		if (tNeedRecomp || this->mEvalUndonePrms->tagged(1) ||
				mTyRec->PrevDiff(this->mTermSys.ExecClk()))
			this->mMetricRec->updtCurr(this->mTermSys.ExecClk(),
					tc<pyt,fmt>::iof(mTyRec->CurrData()));
	}
	else
	{
		Term::performExecBklg(this->mPrmTerms[2]);
		if (tNeedRecomp || this->mEvalUndonePrms->tagged(2) ||
				mEyRec->PrevDiff(this->mTermSys.ExecClk()))
			this->mMetricRec->updtCurr(this->mTermSys.ExecClk(),
					tc<pyt,fmt>::iof(mEyRec->CurrData()));
	}
	this->runPostExecBklg();
	CatchError
}
#endif



/*!
	Compute the term in simulation mode.
*/
template<typename pxt, typename pyt, typename fmt>
void IfteXYFcMt<pxt,pyt,fmt>::simulIncr()
{
	WatchError
	#if SimulUpwd
	if (this->mSimulChgdPrms.tagCount())
	{
		Bll tNeedRecomp = this->mSimulChgdPrms.tagged(0) &&
				mPxRec->NextDiff(this->mTermSys.SimulClk());
		if (tc<pxt,Bll>::iof(mPxRec->NextData(this->mTermSys.SimulClk())))
		{
			if (tNeedRecomp || (this->mSimulChgdPrms.tagged(1) &&
					mTyRec->NextDiff(this->mTermSys.SimulClk())))
				this->mMetricRec->updtNext(this->mTermSys.SimulClk(),
						tc<pyt,fmt>::iof(mTyRec->NextData(this->mTermSys.SimulClk())));
		}
		else
		{
			if (tNeedRecomp || (this->mSimulChgdPrms.tagged(2) &&
					mEyRec->NextDiff(this->mTermSys.SimulClk())))
				this->mMetricRec->updtNext(this->mTermSys.SimulClk(),
						tc<pyt,fmt>::iof(mEyRec->NextData(this->mTermSys.SimulClk())));
		}
		this->runPostSimulIncr();
	}
	#endif	//SimulUpwd
	#if SimulDnwd
	Bll tNeedRecomp = false, tCondMetric;

	#if SimulFixed
	if (this->needSimulFixedComp()) this->markFixedParams();
	#endif
	#if SimulFlexi
	if (this->needSimulFlexiComp()) this->markFlexiParams();
	#endif
	#if CompLazy
	if (!this->backlog())
	{
	#endif	//CompLazy
		#if SimulFixedFlexi
		if (this->mLblFixedPrms.tagged(0) || this->mLblFlexiPrms->tagged(0))
		#endif
		#if SimulFixedOnly
		if (this->mLblFixedPrms.tagged(0))
		#endif
		#if SimulFlexiOnly
		if (this->mLblFlexiPrms->tagged(0))
		#endif
		{
			Term::performSimulIncr(this->mPrmTerms[0]);
			if (mPxRec->NextDiff(this->mTermSys.SimulClk()))
			{
				tNeedRecomp = true;
				tCondMetric = tc<pxt,Bll>::iof(mPxRec->NextData(this->mTermSys.SimulClk()));
			}
		}
		if (!tNeedRecomp)
			tCondMetric = tc<pxt,Bll>::iof(mPxRec->NextData(this->mTermSys.SimulClk()));
		if (tCondMetric)
		{
			#if SimulFixedFlexi
			if (this->mLblFixedPrms.tagged(1) || this->mLblFlexiPrms->tagged(1))
			#endif
			#if SimulFixedOnly
			if (this->mLblFixedPrms.tagged(1))
			#endif
			#if SimulFlexiOnly
			if (this->mLblFlexiPrms->tagged(1))
			#endif
			{
				Term::performSimulIncr(this->mPrmTerms[1]);
				if (tNeedRecomp || mTyRec->NextDiff(this->mTermSys.SimulClk()))
					this->mMetricRec->updtNext(this->mTermSys.SimulClk(),
							tc<pyt,fmt>::iof(mTyRec->NextData(this->mTermSys.SimulClk())));
			}
			#if CompLazy
			else
			{
				Term::performEmulBklg(this->mPrmTerms[1]);
				if (tNeedRecomp || mTyRec->LateDiff(this->mTermSys.EmulClk()))
					this->mMetricRec->updtNext(this->mTermSys.SimulClk(),
							tc<pyt,fmt>::iof(mTyRec->LateData(this->mTermSys.EmulClk())));
			}
			#else
			else
			{
				if (tNeedRecomp)
					this->mMetricRec->updtNext(this->mTermSys.SimulClk(),
							tc<pyt,fmt>::iof(mTyRec->NextData(this->mTermSys.SimulClk())));
			}
			#endif
		}
		else
		{
			#if SimulFixedFlexi
			if (this->mLblFixedPrms.tagged(2) || this->mLblFlexiPrms->tagged(2))
			#endif
			#if SimulFixedOnly
			if (this->mLblFixedPrms.tagged(2))
			#endif
			#if SimulFlexiOnly
			if (this->mLblFlexiPrms->tagged(2))
			#endif
			{
				Term::performSimulIncr(this->mPrmTerms[2]);
				if (tNeedRecomp || mEyRec->NextDiff(this->mTermSys.SimulClk()))
					this->mMetricRec->updtNext(this->mTermSys.SimulClk(),
							tc<pyt,fmt>::iof(mEyRec->NextData(this->mTermSys.SimulClk())));
			}
			#if CompLazy
			else
			{
				Term::performEmulBklg(this->mPrmTerms[2]);
				if (tNeedRecomp || mEyRec->LateDiff(this->mTermSys.EmulClk()))
					this->mMetricRec->updtNext(this->mTermSys.SimulClk(),
							tc<pyt,fmt>::iof(mEyRec->LateData(this->mTermSys.EmulClk())));
			}
			#else
			else
			{
				if (tNeedRecomp)
					this->mMetricRec->updtNext(this->mTermSys.SimulClk(),
							tc<pyt,fmt>::iof(mEyRec->NextData(this->mTermSys.SimulClk())));
			}
			#endif
		}
	#if CompLazy
	}
	else
	{
		#if SimulFixedFlexi
		if (this->mLblFixedPrms.tagged(0) || this->mLblFlexiPrms->tagged(0))
		#endif
		#if SimulFixedOnly
		if (this->mLblFixedPrms.tagged(0))
		#endif
		#if SimulFlexiOnly
		if (this->mLblFlexiPrms->tagged(0))
		#endif
		{
			Term::performSimulIncr(this->mPrmTerms[0]);
			if (this->mEvalUndonePrms->tagged(0) ||
					mPxRec->NextDiff(this->mTermSys.SimulClk()))
			{
				tNeedRecomp = true;
				tCondMetric = tc<pxt,Bll>::iof(mPxRec->NextData(this->mTermSys.SimulClk()));
			}
		}
		else if (this->mBacklogPrms.tagged(0))
		{
			Term::performEmulBklg(this->mPrmTerms[0]);
			if (this->mEvalUndonePrms->tagged(0) ||
					mPxRec->LateDiff(this->mTermSys.EmulClk()))
			{
				tNeedRecomp = true;
				tCondMetric = tc<pxt,Bll>::iof(mPxRec->LateData(this->mTermSys.EmulClk()));
			}
		}
		if (!tNeedRecomp)
			tCondMetric = tc<pxt,Bll>::iof(mPxRec->NextData(this->mTermSys.SimulClk()));
		if (tCondMetric)
		{
			#if SimulFixedFlexi
			if (this->mLblFixedPrms.tagged(1) || this->mLblFlexiPrms->tagged(1))
			#endif
			#if SimulFixedOnly
			if (this->mLblFixedPrms.tagged(1))
			#endif
			#if SimulFlexiOnly
			if (this->mLblFlexiPrms->tagged(1))
			#endif
			{
				Term::performSimulIncr(this->mPrmTerms[1]);
				if (tNeedRecomp || this->mEvalUndonePrms->tagged(1) ||
						mTyRec->NextDiff(this->mTermSys.SimulClk()))
					this->mMetricRec->updtNext(this->mTermSys.SimulClk(),
							tc<pyt,fmt>::iof(mTyRec->NextData(this->mTermSys.SimulClk())));
			}
			else	//	no backlog checking, param1 is assumed to be defered.
			{
				Term::performEmulBklg(this->mPrmTerms[1]);
				if (tNeedRecomp || this->mEvalUndonePrms->tagged(1) ||
						mTyRec->LateDiff(this->mTermSys.EmulClk()))
					this->mMetricRec->updtNext(this->mTermSys.SimulClk(),
							tc<pyt,fmt>::iof(mTyRec->LateData(this->mTermSys.EmulClk())));
			}
		}
		else
		{
			#if SimulFixedFlexi
			if (this->mLblFixedPrms.tagged(2) || this->mLblFlexiPrms->tagged(2))
			#endif
			#if SimulFixedOnly
			if (this->mLblFixedPrms.tagged(2))
			#endif
			#if SimulFlexiOnly
			if (this->mLblFlexiPrms->tagged(2))
			#endif
			{
				Term::performSimulIncr(this->mPrmTerms[2]);
				if (tNeedRecomp || this->mEvalUndonePrms->tagged(2) ||
						mEyRec->NextDiff(this->mTermSys.SimulClk()))
					this->mMetricRec->updtNext(this->mTermSys.SimulClk(),
							tc<pyt,fmt>::iof(mEyRec->NextData(this->mTermSys.SimulClk())));
			}
			else 	//	no backlog checking, param2 is assumed to be defered.
			{
				Term::performEmulBklg(this->mPrmTerms[2]);
				if (tNeedRecomp || this->mEvalUndonePrms->tagged(2) ||
						mEyRec->LateDiff(this->mTermSys.EmulClk()))
					this->mMetricRec->updtNext(this->mTermSys.SimulClk(),
							tc<pyt,fmt>::iof(mEyRec->LateData(this->mTermSys.EmulClk())));
			}
		}
	}
	#endif	//CompLazy
	#endif 	//SimulDnwd
	CatchError
}



#if CompLazy
/*!
	Compute the term in simulation mode.
*/
template<typename pxt, typename pyt, typename fmt>
void IfteXYFcMt<pxt,pyt,fmt>::emulBklg()
{
	WatchError
	Bll tNeedRecomp = false;
	if (this->mBacklogPrms.tagged(0))
	{
		Term::performEmulBklg(this->mPrmTerms[0]);
		if (this->mEvalUndonePrms->tagged(0) ||
				mPxRec->LateDiff(this->mTermSys.EmulClk()))
			tNeedRecomp = true;
	}

	if (tc<pxt,Bll>::iof(mPxRec->LateData(this->mTermSys.EmulClk())))
	{
		Term::performEmulBklg(this->mPrmTerms[1]);
		if (tNeedRecomp || this->mEvalUndonePrms->tagged(1) ||
				mTyRec->LateDiff(this->mTermSys.EmulClk()))
			this->mMetricRec->updtLate(this->mTermSys.EmulClk(),
				tc<pyt,fmt>::iof(mTyRec->LateData(this->mTermSys.EmulClk())));
	}
	else
	{
		Term::performEmulBklg(this->mPrmTerms[2]);
		if (tNeedRecomp || this->mEvalUndonePrms->tagged(2) ||
				mEyRec->LateDiff(this->mTermSys.EmulClk()))
			this->mMetricRec->updtLate(this->mTermSys.EmulClk(),
				tc<pyt,fmt>::iof(mEyRec->LateData(this->mTermSys.EmulClk())));
	}
	CatchError
}
#endif	//CompLazy


closeKangarooSpace


#endif //IfteXYFcMtTccIncluded
