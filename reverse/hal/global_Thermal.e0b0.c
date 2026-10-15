// global_Thermal @ 0xe0b0
void _GLOBAL__sub_I_Thermal_cpp(void)

{
  undefined *puVar1;
  
  puVar1 = PTR_gCallbacks_00116a98;
  *(undefined8 *)(PTR_gCallbacks_00116a98 + 0x10) = 0;
  *(undefined8 *)(puVar1 + 8) = 0;
  *(undefined **)puVar1 = puVar1 + 8;
  __cxa_atexit(std::
               set<android::sp<android::hardware::thermal::V2_0::IThermalChangedCallback>,std::less<android::sp<android::hardware::thermal::V2_0::IThermalChangedCallback>>,std::allocator<android::sp<android::hardware::thermal::V2_0::IThermalChangedCallback>>>
               ::~set,puVar1,&PTR_LOOP_00116000);
  return;
}
