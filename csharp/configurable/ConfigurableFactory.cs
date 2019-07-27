using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;

namespace ConfigurationExample
{
    public static class ConfigurableFactory
    {
        private static readonly Type[] EmptyParameterList = new Type [] {};
        private const BindingFlags AcceptedBindingFlagsOnConfigurables = BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance;

        private static IEnumerable<T> ContainsAttribute<T>(this IEnumerable<T> source, Type attr)
            where T : MemberInfo
        {
            return source.Where(src => src.CustomAttributes
                                .Select(customAttr => customAttr.AttributeType)
                                .Contains(attr));
        }

        private static void AssignPropertiesOnObj(Type t, object obj)
        {
            var configurableProperties = t.GetProperties(AcceptedBindingFlagsOnConfigurables)
                .ContainsAttribute(typeof(ConfigurableAttribute));
            foreach (var configurableProperty in configurableProperties)
            {
                if (configurableProperty.CanWrite)
                {
                    configurableProperty.SetValue(obj, 3);
                }
            }
        }

        private static void AssignFieldsOnObj(Type t, object obj)
        {
            var configurableFields = t.GetFields(AcceptedBindingFlagsOnConfigurables)
                .ContainsAttribute(typeof(ConfigurableAttribute));
            foreach (var configurableField in configurableFields)
            {
                if (!configurableField.IsLiteral)
                {
                    configurableField.SetValue(obj, 5);
                }
            }
        }

        public static T Create<T>()
            where T : class, new()
        {
            var classType = typeof(T);
            var ctor = classType.GetConstructor(EmptyParameterList);
            var obj = ctor.Invoke(null) as T;

            AssignPropertiesOnObj(classType, obj);
            AssignFieldsOnObj(classType, obj);

            return obj;
        }

        public static T Create<T>(params object[] parameters)
            where T : class
        {
            var classType = typeof(T);
            var ctor = classType.GetConstructor(AcceptedBindingFlagsOnConfigurables, null, parameters.Select(o => o.GetType()).ToArray(), null);
            if (ctor == null)
            {
                throw new Exception("Could not find valid ctor for parameters supplied");
            }
            var obj = ctor.Invoke(parameters) as T;

            AssignPropertiesOnObj(classType, obj);
            AssignFieldsOnObj(classType, obj);

            return obj;
        }

    }
}
