/*!
	@file taryxfevt.tcc
	@brief The prototype file for TaryXFeVt template class.
	@details This is the prototype file for TaryXFeVt template class.
	@author M.A.Hakim Newton hakim.newton@nicta.com.au
	@author Duc Nghia Pham duc-nghia.pham@nicta.com.au
	@date 16.11.2009 QRL NICTA www.nicta.com.au
*/



#ifndef TaryXFeVtTccIncluded
#define TaryXFeVtTccIncluded


#include "cbls/funcs/fevs/segfevt.tcc"


openKangarooSpace



/*!
	@class TaryXFeVt
	@brief A template class to represent ternary FeVs.
	@details This template class represents ternary FeVs.
*/
template<typename op>
class TaryXFeVt : public SegFeVt<typename op::OutTyp>
{
	public:
		static Hdl def(Fss const theFss, Hdl const hdlSys, Prm * thePrms);		//!< Definition.
		static Hdl def(Fss const theFss, Hdl const hdlSys, Prm const & Main,
										Prm const & Left, Prm const & Right);	//!< Definition.

		static TaryXFeVt<op> & refm(Hdl const hdlSys, Hdl const hdlFunc);		//!< Reference.
		static TaryXFeVt<op> * ptrm(Hdl const hdlSys, Hdl const hdlFunc);		//!< Pointer.
		static TaryXFeVt<op> const & refc(Hdl const hdlSys, Hdl const hdlFunc);	//!< Reference.
		static TaryXFeVt<op> const * ptrc(Hdl const hdlSys, Hdl const hdlFunc);	//!< Pointer.

		//! @name Casting
		//! @{

		static TaryXFeVt<op> const & cast(Term const & theTerm);		//!< Perform casting.
		static TaryXFeVt<op> const * cast(Term const * theTerm);		//!< Perform casting.
		static TaryXFeVt<op> & cast(Term & theTerm);					//!< Perform casting.
		static TaryXFeVt<op> * cast(Term * theTerm);					//!< Perform casting.

		static Bll suit(Term const & theTerm);					//!< Suits casting?
		static Bll suit(Term const * theTerm);					//!< Suits casting?
		static Bll suit(Term & theTerm);						//!< Suits casting?
		static Bll suit(Term * theTerm);						//!< Suits casting?

		//! @}

	private:

		TaryXFeVt(Fss const theFss, Hdl const hdlSys,
								Prm * thePrms, Dim const PrmCount);		//!< Constructor.
		TaryXFeVt const & operator = (TaryXFeVt<op> const & that);		//!< Assigner.
		TaryXFeVt(TaryXFeVt<op> const & that);							//!< Duplicator.
		~TaryXFeVt();													//!< Destructor.

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

		EvalRec<typename op::InxTyp> const * mPxRecs[op::Arity];	//!< The parameter.
		#if SimulLazy
		Bll 					   			cSimulBklg;				//!< Simulation cache.
		#endif
};



/*!
	Whether a term is suitable for casting.
*/
template<typename op>
inline Bll TaryXFeVt<op>::suit(Term const & theTerm)
{
	WatchError
	return theTerm.TermCls == TermStub< TaryXFeVt<op> >::TermCls;
	CatchError
}



/*!
	Whether a term is suitable for casting.
*/
template<typename op>
inline Bll TaryXFeVt<op>::suit(Term const * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);

	return theTerm->TermCls == TermStub< TaryXFeVt<op> >::TermCls;
	CatchError
}




/*!
	Whether a term is suitable for casting.
*/
template<typename op>
inline Bll TaryXFeVt<op>::suit(Term & theTerm)
{
	WatchError
	return theTerm.TermCls == TermStub< TaryXFeVt<op> >::TermCls;
	CatchError
}



/*!
	Whether a term is suitable for casting.
*/
template<typename op>
inline Bll TaryXFeVt<op>::suit(Term * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);

	return theTerm->TermCls == TermStub< TaryXFeVt<op> >::TermCls;
	CatchError
}



/*!
	Perform casting of a term.
*/
template<typename op>
inline TaryXFeVt<op> & TaryXFeVt<op>::cast(Term & theTerm)
{
	WatchError
	Warn(theTerm.TermCls != TermStub< TaryXFeVt<op> >::TermCls, eWrongCls);

	return scast<TaryXFeVt<op> &>(theTerm);
	CatchError
}



/*!
	Perform casting of a term.
*/
template<typename op>
inline TaryXFeVt<op> * TaryXFeVt<op>::cast(Term * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);
	Warn(theTerm->TermCls != TermStub< TaryXFeVt<op> >::TermCls, eWrongCls);

	return scast<TaryXFeVt<op> *>(theTerm);
	CatchError
}



/*!
	Perform casting of a term.
*/
template<typename op>
inline TaryXFeVt<op> const & TaryXFeVt<op>::cast(Term const & theTerm)
{
	WatchError
	Warn(theTerm.TermCls != TermStub< TaryXFeVt<op> >::TermCls, eWrongCls);

	return scast<TaryXFeVt<op> const &>(theTerm);
	CatchError
}



/*!
	Perform casting of a term.
*/
template<typename op>
inline TaryXFeVt<op> const * TaryXFeVt<op>::cast(Term const * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);
	Warn(theTerm->TermCls != TermStub< TaryXFeVt<op> >::TermCls, eWrongCls);

	return scast<TaryXFeVt<op> const *>(theTerm);
	CatchError
}



/*!
	Refer to a ternary FeV term.
*/
template<typename op>
inline TaryXFeVt<op> & TaryXFeVt<op>::refm(Hdl const hdlSys, Hdl const hdlFunc)
{
	WatchError
	return cast(Sys::refm(hdlSys).refmFunc(hdlFunc));
	CatchError
}



/*!
	Point to a ternary FeV in the sys.
*/
template<typename op>
inline TaryXFeVt<op> * TaryXFeVt<op>::ptrm(Hdl const hdlSys, Hdl const hdlFunc)
{
	WatchError
	return cast(Sys::ptrm(hdlSys)->ptrmFunc(hdlFunc));
	CatchError
}



/*!
	Refer to a ternary FeV term.
*/
template<typename op>
inline TaryXFeVt<op> const & TaryXFeVt<op>::refc(Hdl const hdlSys, Hdl const hdlFunc)
{
	WatchError
	return cast(Sys::refc(hdlSys).refcFunc(hdlFunc));
	CatchError
}



/*!
	Point to a ternary FeV in the sys.
*/
template<typename op>
inline TaryXFeVt<op> const * TaryXFeVt<op>::ptrc(Hdl const hdlSys, Hdl const hdlFunc)
{
	WatchError
	return cast(Sys::ptrc(hdlSys)->ptrcFunc(hdlFunc));
	CatchError
}



/*!
	The destructor.
*/
template<typename op>
inline TaryXFeVt<op>::~TaryXFeVt()
{
	WatchError
	//	nothing to be done.
	CatchError
}


/*!
	Define a FeV in the Sys.
*/
template<typename op>
Hdl TaryXFeVt<op>::def(Fss const theFss, Hdl const hdlSys, Prm const & Main,
		Prm const & Left, Prm const & Right)
{
	WatchError
	Prm tPrms[op::Arity] = { Main, Left, Right };
	return def(theFss, hdlSys, tPrms);
	CatchError
}


/*!
	Define a ory for a ternary FeV.
*/
template<typename op>
Hdl TaryXFeVt<op>::def(Fss const theFss, Hdl const hdlSys, Prm * thePrms)
{
	WatchError
	Warn(op::Arity != 3, eParamCount1(3));

	TaryXFeVt<op> * tFeV = new TaryXFeVt<op>(theFss, hdlSys, thePrms, op::Arity);
	Hdl const tHdl = tFeV->defSysFunc();
	if (tHdl != InvHdl) { delete tFeV; return tHdl; }

	EvalTbl<typename op::OutTyp> & tOutTbl =
				EvalTbl<typename op::OutTyp>::refm(hdlSys);
	EvalTbl<typename op::InxTyp> const & tInxTbl =
				EvalTbl<typename op::InxTyp>::refc(hdlSys);

	b1<Term *,kmm> const & tPrmTerms = tFeV->mPrmTerms;
	b1<Pss,kmm> const & tPrmSpecs = tFeV->mPrmSpecs;

	for(Pos tPos = 0; tPos < op::Arity; ++tPos)
	{
		Loc const tPxLoc = getPxLoc(theFss, tPrmTerms[tPos],tPrmSpecs[tPos]);
		tFeV->mPxRecs[tPos] = tInxTbl.ptrcEvalRec(tPxLoc);
	}

	tOutTbl.setEvalRec(tFeV->mValueRec, tFeV->mValueLoc);

	tFeV->performCompConst();
	tFeV->defSysRoot();
	return tFeV->TermHdl;
	CatchError
}




/*!
	The constructor.
*/
template<typename op>
TaryXFeVt<op>::TaryXFeVt(Fss const theFss, Hdl const hdlSys,
		Prm * thePrms, Dim const PrmCount) :
		SegFeVt<typename op::OutTyp>(hdlSys, PrmCount)
{
	WatchError
	this->setTermCls(TermStub< TaryXFeVt<op> >::TermCls);
	this->setParams(theFss, thePrms, PrmCount, op::Order);
	this->setTermHvl(this->calcTermHvl());
	CatchError
}



/*!
	The duplicator.
*/
template<typename op>
TaryXFeVt<op>::TaryXFeVt(TaryXFeVt<op> const & that) :
		SegFeVt<typename op::OutTyp>(that)
{
	WatchError
	Throw(eUndefDuplicator);
	CatchError
}



/*!
	The assigner.
*/
template<typename op>
TaryXFeVt<op> const & TaryXFeVt<op>::operator = (TaryXFeVt<op> const & that)
{
	WatchError
	Throw(eUndefAssigner);
	CatchError
}



/*!
	Compute the term.
*/
template<typename op>
void TaryXFeVt<op>::compConst()
{
	WatchError
	if (this->updatable())
		this->setUpdatable(op::chk(this->mPrmTerms[0]->updatable(),
			this->mPrmTerms[1]->updatable(), this->mPrmTerms[2]->updatable(),
			mPxRecs[0]->CurrData(),	mPxRecs[1]->CurrData(),
			mPxRecs[2]->CurrData()));

	if (!this->updatable())
		this->mValueRec->finalise(op::iof(mPxRecs[0]->CurrData(),
				mPxRecs[1]->CurrData(), mPxRecs[2]->CurrData()));
	CatchError
}



/*!
	Compute the term in execution mode.
*/
template<typename op>
void TaryXFeVt<op>::execAnew()
{
	WatchError
	#if ExecDnwd
	Term::performExecAnew(this->mPrmTerms[0]);
	Term::performExecAnew(this->mPrmTerms[1]);
	Term::performExecAnew(this->mPrmTerms[2]);
	#endif
	this->mValueRec->initCurr(op::iof(mPxRecs[0]->CurrData(),
				mPxRecs[1]->CurrData(), mPxRecs[2]->CurrData()));
	#if ExecUpwdLazy
	this->runPostExecAnew();
	#endif
	CatchError
}



/*!
	Compute the term in simulation mode.
*/
template<typename op>
void TaryXFeVt<op>::simulAnew()
{
	WatchError
	#if SimulDnwd
	Term::performSimulAnew(this->mPrmTerms[0]);
	Term::performSimulAnew(this->mPrmTerms[1]);
	Term::performSimulAnew(this->mPrmTerms[2]);
	#endif
	this->mValueRec->updtNext(this->mTermSys.SimulClk(),
		op::iof(mPxRecs[0]->NextData(this->mTermSys.SimulClk()),
					mPxRecs[1]->NextData(this->mTermSys.SimulClk()),
					mPxRecs[2]->NextData(this->mTermSys.SimulClk())));
	#if SimulUpwd
	this->runPostSimulAnew();
	#endif
	CatchError
}



/*!
	Compute the term in execution mode.
*/
template<typename op>
void TaryXFeVt<op>::execIncr()
{
	WatchError
	#if ExecUpwd
	if (this->mExecChgdPrms.tagCount())
	{
		if ((this->mExecChgdPrms.tagged(0) &&
				mPxRecs[0]->PrevDiff(this->mTermSys.ExecClk())) ||
			(this->mExecChgdPrms.tagged(1) &&
				mPxRecs[1]->PrevDiff(this->mTermSys.ExecClk())) ||
			(this->mExecChgdPrms.tagged(2) &&
				mPxRecs[2]->PrevDiff(this->mTermSys.ExecClk())))
		this->mValueRec->updtCurr(this->mTermSys.ExecClk(),
			op::iof(mPxRecs[0]->CurrData(), mPxRecs[1]->CurrData(),
						mPxRecs[2]->CurrData()));

		this->runPostExecIncr();
	}
	#endif
	#if ExecDnwd
	Bll tNeedRecomp = false;
	#if CompLazy
	if (!this->backlog())
	{
	#endif	//	CompLazy
		if (this->needExecCandComp()) this->listCandParams();
		for(Idx tIdx = 0; tIdx < this->mBlkCandPrms->itemCount(); ++tIdx)
		{
			Pos const tPos = this->mBlkCandPrms->item(tIdx);
			Term::performExecIncr(this->mPrmTerms[tPos]);
			if (tNeedRecomp) continue;
			if (mPxRecs[tPos]->PrevDiff(this->mTermSys.ExecClk()))
				tNeedRecomp = true;
		}
	#if CompLazy
	}
	else	//	backlog
	{
		if (this->needExecCandComp()) this->markCandParams();
		for(Idx tIdx = 0; tIdx < this->mBlkCandPrms->itemCount(); ++tIdx)
		{
			Pos const tPos = this->mBlkCandPrms->item(tIdx);
			Term::performExecIncr(this->mPrmTerms[tPos]);

			if (tNeedRecomp) continue;
			if (this->mEvalUndonePrms->tagged(tPos) ||
					mPxRecs[tPos]->PrevDiff(this->mTermSys.ExecClk()))
				tNeedRecomp = true;
		}
		for(Idx tIdx = 0; tIdx < this->mBacklogPrms.tagCount(); ++tIdx)
		{
			Pos const tPos = this->mBacklogPrms.serial(tIdx);
			if (this->mLblCandPrms.tagged(tPos)) continue;
			Term::performExecBklg(this->mPrmTerms[tPos]);
			if (tNeedRecomp) continue;
			if (this->mEvalUndonePrms->tagged(tPos) ||
					mPxRecs[tPos]->PrevDiff(this->mTermSys.ExecClk()))
				tNeedRecomp = true;
		}
	}
	#endif	//CompLazy
	if (tNeedRecomp)
		this->mValueRec->updtCurr(this->mTermSys.ExecClk(),
			op::iof(mPxRecs[0]->CurrData(), mPxRecs[1]->CurrData(),
						mPxRecs[2]->CurrData()));
	#endif 	//ExecDnwd
	#if CompLazy
	this->runPostExecIncr();
	#endif
	CatchError
}


#if CompLazy
/*!
	Compute the term in execution mode.
*/
template<typename op>
void TaryXFeVt<op>::execBklg()
{
	WatchError
	Bll tNeedRecomp = false;
	for(Idx tIdx = 0; tIdx < this->mBacklogPrms.tagCount(); ++tIdx)
	{
		Pos const tPos = this->mBacklogPrms.serial(tIdx);
		Term::performExecBklg(this->mPrmTerms[tPos]);
		if (tNeedRecomp) continue;
		if (this->mEvalUndonePrms->tagged(tPos) ||
				mPxRecs[tPos]->PrevDiff(this->mTermSys.ExecClk()))
			tNeedRecomp = true;
	}
	if (tNeedRecomp)
		this->mValueRec->updtCurr(this->mTermSys.ExecClk(),
			op::iof(mPxRecs[0]->CurrData(), mPxRecs[1]->CurrData(),
					mPxRecs[2]->CurrData()));
	this->runPostExecBklg();
	CatchError
}
#endif //CompLazy



/*!
	Compute the term in simulation mode.
*/
template<typename op>
void TaryXFeVt<op>::simulIncr()
{
	WatchError
	#if SimulUpwd
	if (this->mSimulChgdPrms.tagCount())
	{
		if ((this->mSimulChgdPrms.tagged(0) &&
					mPxRecs[0]->NextDiff(this->mTermSys.SimulClk())) ||
				(this->mSimulChgdPrms.tagged(1) &&
					mPxRecs[1]->NextDiff(this->mTermSys.SimulClk())) ||
				(this->mSimulChgdPrms.tagged(2) &&
					mPxRecs[2]->NextDiff(this->mTermSys.SimulClk())))
			this->mValueRec->updtNext(this->mTermSys.SimulClk(),
				op::iof(mPxRecs[0]->NextData(this->mTermSys.SimulClk()),
						mPxRecs[1]->NextData(this->mTermSys.SimulClk()),
						mPxRecs[2]->NextData(this->mTermSys.SimulClk())));
		this->runPostSimulIncr();
	}
	#endif
	#if SimulDnwd
	#if CompLazy
	if (!this->backlog())
	{
	#endif
		Bll tNeedRecomp = false;
		#if SimulFlexi
		if (this->needSimulFlexiComp()) this->listFlexiParams();
		#endif
		#if SimulFixedFlexi
		if (this->needSimulFixedComp())
			this->enumFixedParams(this->mBlkFlexiPrms->itemCount());
		#endif
		#if SimulFixed
		if (this->needSimulFixedComp()) this->listFixedParams();
		#endif

		#if SimulFixed
		for(Idx tIdx = 0; tIdx < this->mBlkFixedPrms->itemCount(); ++tIdx)
		{
			Pos const tPos = this->mBlkFixedPrms->item(tIdx);
			Term::performSimulIncr(this->mPrmTerms[tPos]);
			if (!tNeedRecomp && mPxRecs[tPos]->NextDiff(this->mTermSys.SimulClk()))
				tNeedRecomp = true;
		}
		#endif //SimulFixed

		#if SimulFlexi
		for(Idx tIdx = 0; tIdx < this->mBlkFlexiPrms->itemCount(); ++tIdx)
		{
			Pos const tPos = this->mBlkFlexiPrms->item(tIdx);
			#if SimulFixed
			if (this->mLblFixedPrms.tagged(tPos)) continue;
			#endif
			Term::performSimulIncr(this->mPrmTerms[tPos]);
			if (!tNeedRecomp && mPxRecs[tPos]->NextDiff(this->mTermSys.SimulClk()))
				tNeedRecomp = true;
		}
		#endif	//SimulFlexi

		if (tNeedRecomp)
			this->mValueRec->updtNext(this->mTermSys.SimulClk(),
				op::iof(mPxRecs[0]->NextData(this->mTermSys.SimulClk()),
							mPxRecs[1]->NextData(this->mTermSys.SimulClk()),
							mPxRecs[2]->NextData(this->mTermSys.SimulClk())));
	#if CompLazy
	}
	else
	{
		Bll tNeedRecomp[op::Arity] = { false, false, false };
		#if SimulFlexi
		if (this->needSimulFlexiComp()) this->listFlexiParams();
		#endif
		#if SimulFixed
		if (this->needSimulFixedComp()) this->markFixedParams();
		#endif

		#if SimulFixed
		for(Idx tIdx = 0; tIdx < this->mBlkFixedPrms->itemCount(); ++tIdx)
		{
			Pos const tPos = this->mBlkFixedPrms->item(tIdx);
			Term::performSimulIncr(this->mPrmTerms[tPos]);
			if (this->mEvalUndonePrms->tagged(tPos) ||
					mPxRecs[tPos]->NextDiff(this->mTermSys.SimulClk()))
				tNeedRecomp[tPos] = true;
		}
		#endif //SimulFixed

		if (this->needSimulCacheComp())
		{
			cSimulBklg = false;
			for(Idx tIdx = 0; tIdx < this->mBacklogPrms.tagCount(); ++tIdx)
			{
				Pos const tPos = this->mBacklogPrms.serial(tIdx);
				#if SimulFixed
				if (this->mLblFixedPrms.tagged(tPos)) continue;
				#endif
				Term::performEmulBklg(this->mPrmTerms[tPos]);
				if (!cSimulBklg && (this->mEvalUndonePrms->tagged(tPos) ||
						mPxRecs[tPos]->LateDiff(this->mTermSys.EmulClk())))
					cSimulBklg = true;
			}
		}

		#if SimulFlexi
		for(Idx tIdx = 0; tIdx < this->mBlkFlexiPrms->itemCount(); ++tIdx)
		{
			Pos const tPos = this->mBlkFlexiPrms->item(tIdx);
			#if SimulFixed
			if (this->mLblFixedPrms.tagged(tPos)) continue;
			#endif
			Term::performSimulIncr(this->mPrmTerms[tPos]);
			if (this->mEvalUndonePrms->tagged(tPos) ||
					mPxRecs[tPos]->NextDiff(this->mTermSys.SimulClk()))
				tNeedRecomp[tPos] = true;
		}
		#endif//SimulFlexi

		if (tNeedRecomp[0] || tNeedRecomp[1] || tNeedRecomp[2] || cSimulBklg)
			this->mValueRec->updtNext(this->mTermSys.SimulClk(),
				op::iof((tNeedRecomp[0] ? mPxRecs[0]->NextData(this->mTermSys.SimulClk()) :
											mPxRecs[0]->LateData(this->mTermSys.EmulClk())),
							(tNeedRecomp[1] ? mPxRecs[1]->NextData(this->mTermSys.SimulClk()) :
											mPxRecs[1]->LateData(this->mTermSys.EmulClk())),
							(tNeedRecomp[2] ? mPxRecs[2]->NextData(this->mTermSys.SimulClk()) :
											mPxRecs[2]->LateData(this->mTermSys.EmulClk()))));
	}
	#endif	//	CompLazy
	#endif	//	SimulDnwd
	CatchError
}


#if CompLazy
/*!
	Compute the term in simulation mode.
*/
template<typename op>
void TaryXFeVt<op>::emulBklg()
{
	WatchError
	Bll tNeedRecomp = false;
	for(Idx tIdx = 0; tIdx < this->mBacklogPrms.tagCount(); ++tIdx)
	{
		Pos const tPos = this->mBacklogPrms.serial(tIdx);
		Term::performEmulBklg(this->mPrmTerms[tPos]);
		if (this->mEvalUndonePrms->tagged(tPos) ||
				mPxRecs[tPos]->LateDiff(this->mTermSys.EmulClk()))
			tNeedRecomp = true;
	}
	if (tNeedRecomp)
		this->mValueRec->updtLate(this->mTermSys.EmulClk(),
			op::iof(mPxRecs[0]->LateData(this->mTermSys.EmulClk()),
				mPxRecs[1]->LateData(this->mTermSys.EmulClk()),
				mPxRecs[2]->LateData(this->mTermSys.EmulClk())));
	CatchError
}
#endif //CompLazy


closeKangarooSpace


#endif	//TaryXFeVtTccIncluded
