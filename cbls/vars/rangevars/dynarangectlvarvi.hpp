/*!
	@file dynarangectlvarvi.hpp
	@brief The prototype file for DynaRangeCtlVarVi class.
	@details This is the prototype file for DynaRangeCtlVarVi class.
	@author M.A.Hakim Newton hakim.newton@nicta.com.au
	@author Duc Nghia Pham duc-nghia.pham@nicta.com.au
	@date 16.11.2009 QRL NICTA www.nicta.com.au
	@see dynarangectlvarvi.cpp
*/



#ifndef DynaRangeCtlVarViHppIncluded
#define DynaRangeCtlVarViHppIncluded



#include "cbls/frames/idx.hh"
#include "cbls/vars/reg.hh"



openKangarooSpace



/*!
	@class DynaRangeCtlVarVi
	@brief A class to represent integer dynamic range control variables.
	@details This class represents integer dynamic range control variables.
*/
class DynaRangeCtlVarVi : public RangeVarVi
{
	public:
		static Hdl def(Hdl const hdlSys, Int const & StatLeft = MinInt,
										Int const & StatRight = MaxInt);				//!< Definition.

		void setDynaRangeX(Fss const theFss, Prm const & LeftPrm, Prm const & RightPrm);//!< Range control.

		static DynaRangeCtlVarVi & refm(Hdl const hdlSys, Hdl const hdlVar);			//!< Reference.
		static DynaRangeCtlVarVi * ptrm(Hdl const hdlSys, Hdl const hdlVar);			//!< Pointer.
		static DynaRangeCtlVarVi const & refc(Hdl const hdlSys, Hdl const hdlVar);		//!< Reference.
		static DynaRangeCtlVarVi const * ptrc(Hdl const hdlSys, Hdl const hdlVar);		//!< Pointer.

		//! @name Casting
		//! @{

		static DynaRangeCtlVarVi const & cast(Term const & theTerm);	//!< Perform casting.
		static DynaRangeCtlVarVi const * cast(Term const * theTerm);	//!< Perform casting.
		static DynaRangeCtlVarVi & cast(Term & theTerm);				//!< Perform casting.
		static DynaRangeCtlVarVi * cast(Term * theTerm);				//!< Perform casting.

		static Bll suit(Term const & theTerm);			//!< Suits casting?
		static Bll suit(Term const * theTerm);			//!< Suits casting?
		static Bll suit(Term & theTerm);				//!< Suits casting?
		static Bll suit(Term * theTerm);				//!< Suits casting?

		//! @}

	public:

		//! @name Compatibility
		//!	@{

		virtual Bll identical(Var const * that) const;	//!< Whether identical?
		virtual Bll identical(Var const & that) const;	//!< Whether identical?
		virtual Bll assignable(Var const * that) const;	//!< Whether assignable?
		virtual Bll assignable(Var const & that) const;	//!< Whether assignable?
		virtual Bll swappable(Var const * that) const;	//!< Whether swappable?
		virtual Bll swappable(Var const & that) const;	//!< Whether swappable?

		//!	@}

		//! @name Validity
		//! @{

		virtual Bll validStat(Int const & theInt) const;		//!< Valid with respect to the static domain?
		virtual Bll validDyna(Int const & theInt) const;		//!< Valid with respect to the dynamic domain?
		virtual Bll validStat(Wrp const & theWrp) const;		//!< Valid with respect to the static domain?
		virtual Bll validDyna(Wrp const & theWrp) const;		//!< Valid with respect to the dynamic domain?

		//! @}

		//! @name Probing
		//! @{

		virtual Bll chkCurrStatRight() const;			//!< Whether the current value is the static right value.
		virtual Bll chkCurrStatLeft() const;			//!< Whether the current value is the static left value.
		virtual Bll chkCurrDynaRight() const;			//!< Whether the current value is the static right value.
		virtual Bll chkCurrDynaLeft() const;			//!< Whether the current value is the static left value.
		virtual Bll chkNextStatRight() const;			//!< Whether the next value is the static right value.
		virtual Bll chkNextStatLeft() const;			//!< Whether the next value is the static left value.
		virtual Bll chkNextDynaRight() const;			//!< Whether the next value is the dynamic right value.
		virtual Bll chkNextDynaLeft() const;			//!< Whether the next value is the dynamic left value.

		//! @}

		//! @name Values
		//! @{

		virtual Int StatRandValue(Rnd & theRnd) const;	//!< Random value chosen from the static domain.
		virtual Int DynaRandValue(Rnd & theRnd) const;	//!< Random value chosen from the dynamic domain.

		virtual Int StatLeftValue() const;				//!< The static left value.
		virtual Int StatRightValue() const;				//!< The static right value.
		virtual Int DynaLeftValue() const;				//!< The dynamic right value.
		virtual Int DynaRightValue() const;				//!< The dynamic right value.
		virtual Int StepSizeValue() const;				//!< The step size value.

		//! @}
		//! @name Wrappers
		//! @{

		virtual Wrp StatRandWrap(Rnd & theRnd) const;	//!< Random value chosen from the static domain.
		virtual Wrp DynaRandWrap(Rnd & theRnd) const;	//!< Random value chosen from the dynamic domain.

		virtual Wrp StatLeftWrap() const;				//!< Wrap for the static left value.
		virtual Wrp StatRightWrap() const;				//!< Wrap for the static right value.
		virtual Wrp DynaLeftWrap() const;				//!< Wrap for the dynamic right value.
		virtual Wrp DynaRightWrap() const;				//!< Wrap for the dynamic right value.
		virtual Wrp StepSizeWrap() const;				//!< Wrap for the step size value.

		//! @}

		//! @name Executions
		//! @{

		virtual void execAnewValue(Int const & theInt);		//!< Execute anew with a given value.
		virtual void execAnewWrap(Wrp const & theWrp);		//!< Execute anew with a given value.
		virtual void execAnewStatRand(Rnd & theRnd);		//!< Execute anew with a random value form the static domain.
		virtual void execAnewDynaRand(Rnd & theRnd);		//!< Execute anew with a random value from the dynamic domain.

		virtual void execIncrValue(Int const & theInt);		//!< Execute incrementally with a given value.
		virtual void execIncrWrap(Wrp const & theWrp);		//!< Execute incrementally with a given value.
		virtual void execIncrStatRand(Rnd & theRnd);		//!< Execute incrementally with a random value form the static domain.
		virtual void execIncrDynaRand(Rnd & theRnd);		//!< Execute incrementally with a random value from the dynamic domain.

		virtual void execIncrStatLeft();					//!< Execute with the static left value.
		virtual void execIncrDynaLeft();					//!< Execute with the dynamic left value.
		virtual void execIncrSuccessor();					//!< Execute with the succeeding value.
		virtual void execIncrPredecessor();					//!< Execute with the preceding value.
		virtual void execIncrStatRight();					//!< Execute with the static right value.
		virtual void execIncrDynaRight();					//!< Execute with the dynamic right value.

		//! @}

		//! @name Simulations
		//! @{

		virtual void simulAnewValue(Int const & theInt);	//!< Simulate anew with a given value.
		virtual void simulAnewWrap(Wrp const & theWrp);		//!< Simulate anew with a given value.
		virtual void simulAnewStatRand(Rnd & theRnd);		//!< Simulate anew with a random value form the static domain.
		virtual void simulAnewDynaRand(Rnd & theRnd);		//!< Simulate anew with a random value from the dynamic domain.

		virtual void simulIncrValue(Int const & theInt);	//!< Simulate incrementally with a given value.
		virtual void simulIncrWrap(Wrp const & theWrp);		//!< Simulate incrementally with a given value.
		virtual void simulIncrStatRand(Rnd & theRnd);		//!< Simulate incrementally with a random value form the static domain.
		virtual void simulIncrDynaRand(Rnd & theRnd);		//!< Simulate incrementally with a random value from the dynamic domain.

		virtual void simulIncrStatLeft();					//!< Simulate with the static left value.
		virtual void simulIncrDynaLeft();					//!< Simulate with the dynamic left value.
		virtual void simulIncrSuccessor();					//!< Simulate with the succeeding value.
		virtual void simulIncrPredecessor();				//!< Simulate with the preceding value.
		virtual void simulIncrStatRight();					//!< Simulate with the static right value.
		virtual void simulIncrDynaRight();					//!< Simulate with the dynamic right value.

		//! @}

		virtual void updateDomain();				//!< Update the domain.
		virtual Bll DomainUpdateDefined() const;	//!< Domain update defined.

	protected:

		~DynaRangeCtlVarVi();													//!< Destructor.
		DynaRangeCtlVarVi(DynaRangeCtlVarVi const & that);						//!< Duplicator.
		DynaRangeCtlVarVi const & operator = (DynaRangeCtlVarVi const & that);	//!< Assigner.
		DynaRangeCtlVarVi(Hdl const hdlSys, Int const & StatLeft,
										Int const & StatRight);					//!< Constructor.

		Int const 		mStatLeftValue;					//!< The static left value.
		Int const 		mStatRightValue;				//!< The static right value.
		Term * 			mDynaLeftTerm;					//!< The dynamic left term value.
		Term * 			mDynaRightTerm;					//!< The dynamic right term value.
		EvalRecInt const * mDynaLeftRec;				//!< Holds the dynamic left value
		EvalRecInt const * mDynaRightRec;				//!< Holds the dynamic right value.
		Int 			mDynaLeftValue;					//!< Holds the dynamic left value.
		Int 			mDynaRightValue;				//!< Holds the dynamic right value.
};



/*!
	Whether a term is suitable for casting.
*/
inline Bll DynaRangeCtlVarVi::suit(Term const & theTerm)
{
	WatchError
	return theTerm.TermCls == TermStub<DynaRangeCtlVarVi>::TermCls;
	CatchError
}



/*!
	Whether a term is suitable for casting.
*/
inline Bll DynaRangeCtlVarVi::suit(Term const * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);

	return theTerm->TermCls == TermStub<DynaRangeCtlVarVi>::TermCls;
	CatchError
}


/*!
	Whether a term is suitable for casting.
*/
inline Bll DynaRangeCtlVarVi::suit(Term & theTerm)
{
	WatchError
	return theTerm.TermCls == TermStub<DynaRangeCtlVarVi>::TermCls;
	CatchError
}



/*!
	Whether a term is suitable for casting.
*/
inline Bll DynaRangeCtlVarVi::suit(Term * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);

	return theTerm->TermCls == TermStub<DynaRangeCtlVarVi>::TermCls;
	CatchError
}



/*!
	Perform casting of a term.
*/
inline DynaRangeCtlVarVi const & DynaRangeCtlVarVi::cast(Term const & theTerm)
{
	WatchError
	Warn(theTerm.TermCls != TermStub<DynaRangeCtlVarVi>::TermCls, eWrongCls);

	return scast<DynaRangeCtlVarVi const &>(theTerm);
	CatchError
}



/*!
	Perform casting of a term.
*/
inline DynaRangeCtlVarVi const * DynaRangeCtlVarVi::cast(Term const * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);
	Warn(theTerm->TermCls != TermStub<DynaRangeCtlVarVi>::TermCls, eWrongCls);

	return scast<DynaRangeCtlVarVi const *>(theTerm);
	CatchError
}



/*!
	Perform casting of a term.
*/
inline DynaRangeCtlVarVi & DynaRangeCtlVarVi::cast(Term & theTerm)
{
	WatchError
	Warn(theTerm.TermCls != TermStub<DynaRangeCtlVarVi>::TermCls, eWrongCls);

	return scast<DynaRangeCtlVarVi &>(theTerm);
	CatchError
}



/*!
	Perform casting of a term.
*/
inline DynaRangeCtlVarVi * DynaRangeCtlVarVi::cast(Term * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);
	Warn(theTerm->TermCls != TermStub<DynaRangeCtlVarVi>::TermCls, eWrongCls);

	return scast<DynaRangeCtlVarVi *>(theTerm);
	CatchError
}



/*!
	Refer to an integer range variable.
*/
inline DynaRangeCtlVarVi & DynaRangeCtlVarVi::refm(Hdl const hdlSys, Hdl const hdlVar)
{
	WatchError
	return cast(Sys::refm(hdlSys).refmVar(hdlVar));
	CatchError
}



/*!
	Point to an integer range variable.
*/
inline DynaRangeCtlVarVi * DynaRangeCtlVarVi::ptrm(Hdl const hdlSys, Hdl const hdlVar)
{
	WatchError
	return cast(Sys::ptrm(hdlSys)->ptrmVar(hdlVar));
	CatchError
}



/*!
	Refer to an integer range variable.
*/
inline DynaRangeCtlVarVi const & DynaRangeCtlVarVi::refc(Hdl const hdlSys, Hdl const hdlVar)
{
	WatchError
	return cast(Sys::refc(hdlSys).refcVar(hdlVar));
	CatchError
}



/*!
	Point to an integer range variable.
*/
inline DynaRangeCtlVarVi const * DynaRangeCtlVarVi::ptrc(Hdl const hdlSys, Hdl const hdlVar)
{
	WatchError
	return cast(Sys::ptrc(hdlSys)->ptrcVar(hdlVar));
	CatchError
}




closeKangarooSpace


#endif //DynaRangeCtlVarViHppIncluded
