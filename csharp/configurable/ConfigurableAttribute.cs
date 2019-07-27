using System;

namespace ConfigurationExample
{
    [System.AttributeUsage(AttributeTargets.Property | AttributeTargets.Field, AllowMultiple = false, Inherited = false)]
    public class ConfigurableAttribute : Attribute
    {}
}
