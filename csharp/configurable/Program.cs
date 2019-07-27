using System;

namespace ConfigurationExample
{
    class MyConfigurableClass
    {
        [Configurable]
        private int PrivateField = 0;
        [Configurable]
        protected int ProtectedField = 0;
        [Configurable]
        internal int InternalField = 0;
        [Configurable]
        public int PublicField = 0;
        [Configurable]
        readonly int ReadonlyField = 0;
        [Configurable]
        const int ConstField = 0;

        [Configurable]
        private int PrivateReadWriteProperty { get; set; } = 0;
        [Configurable]
        internal int InternalReadWriteProperty { get; set; } = 0;
        [Configurable]
        protected int ProtectedReadWriteProperty { get; set; } = 0;
        [Configurable]
        public int PublicReadWriteProperty { get; set; } = 0;
        [Configurable]
        public int PrivateSetterProperty { get; private set; } = 0;
        [Configurable]
        int ReadOnlyProperty { get; } = 0;

        public override string ToString()
        {
            return
                "PrivateField : " + PrivateField + "\n" +
                "ProtectedField : " + ProtectedField + "\n" +
                "InternalField : " + InternalField + "\n" +
                "PublicField : " + PublicField + "\n" +
                "ReadonlyField : " + ReadonlyField + "\n" +
                "ConstField : " + ConstField + "\n" +
                "\n" +
                "PrivateReadWriteProperty : " + PrivateReadWriteProperty + "\n" +
                "InternalReadWriteProperty : " + InternalReadWriteProperty + "\n" +
                "ProtectedReadWriteProperty : " + ProtectedReadWriteProperty + "\n" +
                "PublicReadWriteProperty : " + PublicReadWriteProperty + "\n" +
                "PrivateSetterProperty : " + PrivateSetterProperty + "\n" +
                "ReadOnlyProperty : " + ReadOnlyProperty;
        }
    }

    class MyDerivedConfigurableClass : MyConfigurableClass
    {
        public override string ToString()
        {
            return base.ToString();
        }
    }

    class MyClassWithCustomCtor
    {
        [Configurable]
        int FieldSetViaConfig = 0;
        int FieldSetViaCtor = 0;

        MyClassWithCustomCtor(int a, int b)
        {
            this.FieldSetViaConfig = a;
            this.FieldSetViaCtor = b;
        }
        public override string ToString()
        {
            return
                "FieldSetViaConfig : " + FieldSetViaConfig + "\n" +
                "FieldSetViaCtor : " + FieldSetViaCtor;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("myConfigurable");
            Console.WriteLine("");
            var myConfigurable = ConfigurableFactory.Create<MyConfigurableClass>();
            Console.WriteLine(myConfigurable.ToString());
            Console.WriteLine("");
            Console.WriteLine("myDerivedConfigurable");
            Console.WriteLine("");
            var myDerivedConfigurable = ConfigurableFactory.Create<MyDerivedConfigurableClass>();
            Console.WriteLine(myDerivedConfigurable.ToString());
            Console.WriteLine("");
            Console.WriteLine("myClassWithCustomCtor");
            Console.WriteLine("");
            var myClassWithCustomCtor = ConfigurableFactory.Create<MyClassWithCustomCtor>(11, 12);
            Console.WriteLine(myClassWithCustomCtor.ToString());
        }
    }
}
