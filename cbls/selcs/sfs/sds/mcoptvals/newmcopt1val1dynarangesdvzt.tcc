/*!
	@file newmcopt1val1dynarangesdvzt.tcc
	@brief The source file for McOpt1Val1DynaRangeSdVZt template class.
	@details This is the source file for McOpt1Val1DynaRangeSdVZt template class.
	@author M.A.Hakim Newton hakim.newton@nicta.com.au
	@author Duc Nghia Pham duc-nghia.pham@nicta.com.au
	@date 16.11.2009 QRL NICTA www.nicta.com.au
*/



#ifndef McOpt1Val1DynaRangeSdVZtTccIncluded
#define McOpt1Val1DynaRangeSdVZtTccIncluded



#include "cbls/frames/idx.hh"
#include "cbls/dbases/idx.hpp"


openKangarooSpace



/*!
	@class McOpt1Val1DynaRangeSdVZt
	@brief A template class to represent Monte Carlo optimum value dynamic range single variable selcs.
	@details This template class represents Monte Carlo optimum value dynamic range single variable selcs.
*/
template<typename vt, typename zt, Ord theOrd>
class McOpt1Val1DynaRangeSdVZt : public SdZt<zt>
{
	public:

		static Hdl def(Fss const theFss, Hdl const hdlSys,
									Prm const & prmTerm, Dim const SamplePercent);	//!< Define a selc.

		static McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> &
							refm(Hdl const hdlSys, Hdl const hdlSelc);				//!< Refer to a selc.
		static McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> *
							ptrm(Hdl const hdlSys, Hdl const hdlSelc);				//!< Point to a selc.
		static McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const &
							refc(Hdl const hdlSys, Hdl const hdlSelc);				//!< Refer to a selc.
		static McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const *
							ptrc(Hdl const hdlSys, Hdl const hdlSelc);				//!< Point to a selc.

		//! @name Casting
		//! @{

		static Bll suit(Selc & theSelc);				//!< Suits casting?
		static Bll suit(Selc * theSelc);				//!< Suits casting?
		static Bll suit(Selc const & theSelc);			//!< Suits casting?
		static Bll suit(Selc const * theSelc);			//!< Suits casting?

		static McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> & cast(Selc & theSelc);				//!< Perform casting.
		static McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> * cast(Selc * theSelc);				//!< Perform casting.
		static McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const & cast(Selc const & theSelc);	//!< Perform casting.
		static McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const * cast(Selc const * theSelc);	//!< Perform casting.

		//! @}

	private:

		McOpt1Val1DynaRangeSdVZt(Fss const theFss, Hdl const hdlSys,
						Prm * prmTerm, Dim const PrmCount, Dim const SamplePercent);		//!< Constructor.
		McOpt1Val1DynaRangeSdVZt(McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const & that);		//!< Duplicator.
		McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const & operator =
									(McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const & that);	//!< Assigner.
		~McOpt1Val1DynaRangeSdVZt();														//!< Destructor.

		virtual Bll select(Rnd & theRnd);					//!< Run the selc in the sys.
		#if CompLazyHalf
		virtual void require(Bll const SetNotUnset);		//!< Requirement for the selector.
		#endif
		EvalRec<zt> const * mPzRec;							//!< Point to the metric.
		Dim mSamplePercent;									//!< Sample percentage.
};



/*!
	Whether a selector for casting.
*/
template<typename vt, typename zt, Ord theOrd>
inline Bll McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::suit(Selc const & theSelc)
{
	WatchError
	return theSelc.SelcCls == SelcStub< McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> >::SelcCls;
	CatchError
}



/*!
	Whether a selector for casting.
*/
template<typename vt, typename zt, Ord theOrd>
inline Bll McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::suit(Selc const * theSelc)
{
	WatchError
	Warn(!theSelc, eNullPointer);

	return theSelc->SelcCls == SelcStub< McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> >::SelcCls;
	CatchError
}



/*!
	Whether a selector for casting.
*/
template<typename vt, typename zt, Ord theOrd>
inline Bll McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::suit(Selc & theSelc)
{
	WatchError
	return theSelc.SelcCls == SelcStub< McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> >::SelcCls;
	CatchError
}



/*!
	Whether a selector for casting.
*/
template<typename vt, typename zt, Ord theOrd>
inline Bll McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::suit(Selc * theSelc)
{
	WatchError
	Warn(!theSelc, eNullPointer);

	return theSelc->SelcCls == SelcStub< McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> >::SelcCls;
	CatchError
}



/*!
	Perform casting of a term.
*/
template<typename vt, typename zt, Ord theOrd>
inline McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> &
McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::cast(Selc & theSelc)
{
	WatchError
	Wchk(theSelc.SelcCls != SelcStub< McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> >::SelcCls) Wtxt(eWrongCls);

	return scast<McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> &>(theSelc);
	CatchError
}



/*!
	Perform casting of a term.
*/
template<typename vt, typename zt, Ord theOrd>
inline McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> *
McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::cast(Selc * theSelc)
{
	WatchError
	Warn(!theSelc, eNullPointer);
	Wchk(theSelc->SelcCls != SelcStub< McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> >::SelcCls) Wtxt(eWrongCls);

	return scast<McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> *>(theSelc);
	CatchError
}



/*!
	Perform casting of a term.
*/
template<typename vt, typename zt, Ord theOrd>
inline McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const &
McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::cast(Selc const & theSelc)
{
	WatchError
	Wchk(theSelc.SelcCls != SelcStub< McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> >::SelcCls) Wtxt(eWrongCls);

	return scast<McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const &>(theSelc);
	CatchError
}



/*!
	Perform casting of a term.
*/
template<typename vt, typename zt, Ord theOrd>
inline McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const *
McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::cast(Selc const * theSelc)
{
	WatchError
	Warn(!theSelc, eNullPointer);
	Wchk(theSelc->SelcCls != SelcStub< McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> >::SelcCls) Wtxt(eWrongCls);

	return scast<McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const *>(theSelc);
	CatchError
}



/*!
	Refer to a selc in the sys.
*/
template<typename vt, typename zt, Ord theOrd>
inline McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> &
McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::refm(Hdl const hdlSys, Hdl const hdlSelc)
{
	WatchError
	return cast(Sys::refm(hdlSys).refmSelc(hdlSelc));
	CatchError
}



/*!
	Point to a selc in the sys.
*/
template<typename vt, typename zt, Ord theOrd>
inline McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> *
McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::ptrm(Hdl const hdlSys, Hdl const hdlSelc)
{
	WatchError
	return cast(Sys::ptrm(hdlSys)->ptrmSelc(hdlSelc));
	CatchError
}



/*!
	Refer to a selc in the sys.
*/
template<typename vt, typename zt, Ord theOrd>
inline McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const &
McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::refc(Hdl const hdlSys, Hdl const hdlSelc)
{
	WatchError
	return cast(Sys::refc(hdlSys).refcSelc(hdlSelc));
	CatchError
}



/*!
	Point to a selc in the sys.
*/
template<typename vt, typename zt, Ord theOrd>
inline McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const *
McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::ptrc(Hdl const hdlSys, Hdl const hdlSelc)
{
	WatchError
	return cast(Sys::ptrc(hdlSys)->ptrcSelc(hdlSelc));
	CatchError
}




/*!
	The destructor.
*/
template<typename vt, typename zt, Ord theOrd>
inline McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::~McOpt1Val1DynaRangeSdVZt()
{
	WatchError
	//	nothing to be done.
	CatchError
}


/*!
	The duplicator.
*/
template<typename vt, typename zt, Ord theOrd>
McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::McOpt1Val1DynaRangeSdVZt
		(McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const & that) : SdZt<zt>(that)
{
	WatchError
	Throw(eUndefDuplicator);
	CatchError
}



/*!
	The assigner.
*/
template<typename vt, typename zt, Ord theOrd>
McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const &
McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::operator =
		(McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> const & that)
{
	WatchError
	Throw(eUndefAssigner);
	CatchError
}



/*!
	Define a select in the solver.
*/
template<typename vt, typename zt, Ord theOrd>
Hdl McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::def(Fss const theFss, Hdl const hdlSys,
		Prm const & prmTerm, Dim const SamplePercent)
{
	WatchError
	Prm tPrms[1] = { prmTerm };
	McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> * tSdXF =
		new McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>(theFss, hdlSys, tPrms, 1, SamplePercent);
	Hdl const tHdl = tSdXF->defSysSelc();
	if (tHdl != InvHdl) { delete tSdXF; return tHdl; }

	EvalTbl<zt> const & tPztTbl = EvalTbl<zt>::refc(hdlSys);

	Loc const tPzLoc = getPzLoc(theFss, tSdXF->mPrmTerms[0], prmTerm.PrmSpec);
	tSdXF->mPzRec = tPztTbl.ptrcEvalRec(tPzLoc);

	return tSdXF->SelcHdl;
	CatchError
}



/*!
	The constructor.
*/
template<typename vt, typename zt, Ord theOrd>
McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::McOpt1Val1DynaRangeSdVZt(Fss const theFss, Hdl const hdlSys,
		Prm * thePrms, Dim const PrmCount, Dim const SamplePercent) : SdZt<zt>(hdlSys, PrmCount),
				mSamplePercent(SamplePercent)
{
	WatchError
	Warn(!SamplePercent, eEmptyDimension);
	this->setSelcCls(SelcStub< McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd> >::SelcCls);
	this->setParams(theFss, thePrms, PrmCount);
	this->setSelcHvl(this->calcSelcHvl());
	CatchError
}


#if CompLazyHalf
/*!
	Set requirement for the selector.
*/
template<typename vt, typename zt, Ord theOrd>
void McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::require(Bll const SetNotUnset)
{
	WatchError
	Warn(this->mSelcSys.chkExecMode(NullComp), eSysUninit);
	Func::cast(this->mPrmTerms[0])->require(SetNotUnset);
	CatchError
}
#endif


/*!
	Perform selection.
*/
template<typename vt, typename zt, Ord theOrd>
Bll McOpt1Val1DynaRangeSdVZt<vt,zt,theOrd>::select(Rnd & theRnd)
{
	WatchError
	Warn(this->mSelcVars.itemCount() != 1, eSelcVarCount(1));

	Hdl tVarHdl = this->mSelcVars[0];
	RangeVarVt<vt> & tRangeVar = RangeVarVt<vt>::cast(this->mSelcSys.refmVar(tVarHdl));
	Warn(tRangeVar.ValueType() != DataStub<vt>::DataTyp, eWrongTyp);

	#if CompLazy
	if (tRangeVar.DomainUpdateDefined())
	{
		#if CompLazyHalf
		if (!tRangeVar.DomainUpdateRequired())
		#endif
			tRangeVar.updateDomain();
	}
	#endif

	#if SimulFixedFlexi
		#if SelcSimulFlexi
		this->mSelcSys.setSimulFlexiVar1(tVarHdl);
		#else
		this->mSelcSys.setSimulFixedVar1(tVarHdl);
		#endif
	#elif SimulFixedOnly
	this->mSelcSys.setSimulFixedVar1(tVarHdl);
	#elif SimulFlexiOnly
	this->mSelcSys.setSimulFlexiVar1(tVarHdl);
	#endif

	this->mSelcVals.clear();
	zt tRunZ = OrdStub<theOrd,zt,Bll>::Last0;

	vt tLeftV = tRangeVar.DynaLeftValue();
	vt tRightV = tRangeVar.DynaRightValue();
	vt tStepV = tRangeVar.StepSizeValue();

//	cerr << "Static: " << tRangeVar.StatLeftValue() << ", " << tRangeVar.StatRightValue()
//		 << " == Dynamic: " << tLeftV << ", " << tRightV << endl;
//	cerr << "tStepV " << tStepV << endl;

	Dim tSampleCount = (tRightV - tLeftV + 1) / tStepV * mSamplePercent / 100;
	// This variable can be turned into a parameter
	Dim tSparseCount = tSampleCount * 50 / 100;

	if ( !tSparseCount ) {
		this->mSelcVals.clear();
		this->mSelcVals.insertMem( Wrp(tLeftV) );
		return this->mSelcVals.itemCount();
	}

	vt tSparseStepV = (tRightV - tLeftV + 1) / tSparseCount;

	vt tSparseV     = tLeftV;
	vt tSparseBestV = tLeftV;
	for(Idx tIdx = 0; tIdx <= tSparseCount + 1; ++tIdx)
	{
//		cerr << "  tSparse: " << tSparseV << endl;
		this->mSelcSys.setSimulMode(DiffAsgn);
		tRangeVar.simulIncrWrap( Wrp(tSparseV) );
		this->mSelcSys.setSimulMode(DiffProp);
		#if SimulUpwd
		this->mSelcSys.propagateSimulIncr();
		#endif
		#if SimulDnwd
		Term::performSimulIncr(this->mPrmTerms[0]);
		#endif

		zt tNextZ = mPzRec->NextData(this->mSelcSys.SimulClk());
		if (OrdStub<theOrd,zt,Bll>::RegOp::iof(tNextZ, tRunZ))
		{
			tSparseBestV = tSparseV;
			tRunZ = tNextZ;
//			cerr << "  sparse " << tSparseBestV << " :: " << FuncNextValue<Flt>(0, this->mPrmTerms[0]->TermHdl) << " run " <<  tRunZ << endl;
		}

		tSparseV += tSparseStepV;
		if ( tSparseV > tRightV )
			tSparseV = tRightV;
	}

//	cerr << "tSparseBestV " << tSparseBestV << endl;

	this->mSelcVals.clear();
	this->mSelcVals.insertMem(Wrp(tSparseBestV));

	Dim tDenseCount = tSampleCount - tSparseCount;
//	cerr << "tSpareCount : " << tSparseCount << "  tDenseCount : " << tDenseCount << endl;

	vt tDenseLeftV  = tSparseBestV - 2*tDenseCount * tStepV;
	if ( tDenseLeftV < tLeftV )
		tDenseLeftV = tLeftV;
	vt tDenseRightV = tSparseBestV + 2*tDenseCount * tStepV;
	if ( tDenseRightV > tRightV )
		tDenseRightV = tRightV;

	for(Idx tIdx = 0; tIdx < tDenseCount; ++tIdx)
	{
		this->mSelcSys.setSimulMode(DiffAsgn);
		tRangeVar.simulIncrWrap( Wrp(emu::uniform(theRnd, tDenseLeftV, tDenseRightV)) );
		this->mSelcSys.setSimulMode(DiffProp);
		#if SimulUpwd
		this->mSelcSys.propagateSimulIncr();
		#endif
		#if SimulDnwd
		Term::performSimulIncr(this->mPrmTerms[0]);
		#endif

		zt tNextZ = mPzRec->NextData(this->mSelcSys.SimulClk());
		if (OrdStub<theOrd,zt,Bll>::RegOp::iof(tNextZ, tRunZ))
		{
			this->mSelcVals.clear();
			this->mSelcVals.insertMem(Wrp(tRangeVar.NextValue()));
			tRunZ = tNextZ;

//			cerr << "  dense " << tRangeVar.NextValue() << " :: " << FuncNextValue<Flt>(0, this->mPrmTerms[0]->TermHdl) << " run " << tRunZ << endl;

		}
		else if (eq<zt,Bll>::iof(tNextZ, tRunZ)) {
			this->mSelcVals.insertMem(Wrp(tRangeVar.NextValue()));
//			cerr << "  dense " << tRangeVar.NextValue() << " :: " << FuncNextValue<Flt>(0, this->mPrmTerms[0]->TermHdl) << " run " <<  tRunZ << endl;
		}
	}
	if (this->mSelcVals.itemCount() > 1)
	{
		Itr tItr = uniform(theRnd, this->mSelcVals.itemCount());
		Wrp tWrap = this->mSelcVals.item(tItr);
//		cerr << "--- select " << tWrap.itemInt() << endl;
		this->mSelcVals.clear();
		this->mSelcVals.insertMem(tWrap);
	}
//	cerr << "Inside selector HDL : " << this->mPrmTerms[0]->TermHdl
//		 << " and current value " << FuncCurrValue<Flt>(0, this->mPrmTerms[0]->TermHdl) << endl;
	return this->mSelcVals.itemCount();
	CatchError
}


closeKangarooSpace


#endif	//McOpt1Val1DynaRangeSdVZtTccIncluded
