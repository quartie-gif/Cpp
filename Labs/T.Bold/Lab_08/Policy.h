#pragma once 

#include <iostream>

/***
*   @brief Base class that represents a policy
*/
struct Policy {

	// Method that returns a name of Policy
	virtual std::string policyName() const = 0;

};

/***
*   @brief Class that represents cache policy
*/
struct CachePolicy : public Policy 
{

    virtual void cacheValueForArgument( double arg, double val ) const = 0; // Remembers a value for further calculations

    virtual bool hasCacheFor( double arg ) const = 0;  //Returns a true if in Cache there is a value for an argument
    virtual double getCached(double arg) const = 0; // Remembers an argument

    virtual std::string policyName() const  { return ""; };	
};


/***
*   @brief Class that represents no cache policy
*/
struct NoCache : public CachePolicy 
{

    virtual void cacheValueForArgument( double arg, double val ) const override
    {

    }

    virtual bool hasCacheFor( double arg ) const override
    {
        return false;
    }

    virtual double getCached(double arg) const override
    {
        return 0.0;
    }

    virtual std::string policyName() const override 
    {
        return "NoCache";
    }
};

/***
*   @brief Class that represents one call cache policy
*/
struct OneCallCache : public CachePolicy 
{

    virtual void cacheValueForArgument( double arg, double val ) const override
    {
        _cacheArg = arg;
        _cacheVal = val;
    }

    virtual bool hasCacheFor( double arg ) const override
    {
        return _cacheArg == arg;
    }

    virtual double getCached(double arg) const override
    {
        return _cacheVal;
    }

    virtual std::string policyName() const override 
    {
        return "OneCallCache";
    }

    //Fields are mutable to avoid error: cannot assign to non-static data member within const member function 'cacheValueForArgument'
	mutable double _cacheArg = 0;   // an argument
	mutable double _cacheVal = 0;	// value for an argument
};

/***
*   @brief Class that represents verbosity policy
*/
struct VerbosityPolicy : public Policy 
{
    virtual void printArgAndResult( double arg, double val) const = 0; // Streaming an argument and the value

    virtual std::string policyName() const  = 0;	
};

/***
*   @brief Class that represents silent policy
*/
struct Silent : public VerbosityPolicy 
{
    virtual void printArgAndResult( double arg, double val) const override
    {

    }

    virtual std::string policyName() const override
    {
        return "Silent";
    }	
    
};

/***
*   @brief Class that represents verbose policy
*/
struct Verbose : public VerbosityPolicy 
{
    virtual void printArgAndResult( double arg, double val) const override
    {
        std::cout << "f(" << arg << ") = " << val << std::endl;
    }

    virtual std::string policyName() const override
    {
        return "Verbose";
    }	
   
};